/***************
 * MODUL:         water
 * NAME:          water.cpp
 * DESCRIPTION:   Water texture
 *	AUTHORS:			Andreas Heumann, Mike Hesser
 * HISTORY:
 *		DATE		NAME	COMMENT
 *		27.01.97	ah		initial release
 ***************/

#include "math.h"

#ifndef TYPEDEFS_H
#include "typedefs.h"
#endif

#ifndef VECMATH_H
#include "vecmath.h"
#endif

#ifndef IMTEXTURE_H
#include "imtextur.h"
#endif

// PROTOTYPES

#ifdef __AMIGA__
struct ExecBase *SysBase;
TTABLE *texture_init(LONG);
#else
TTABLE *texture_init(int, int);
#endif
void fwork(FRACT *, PATCH *, VECTOR *, FRACT *);

// INITIALIZATIONS

// infotext[][] is an array of strings that contain the texture name and
// all the text fields that appear in the texture requester.  The
// texture name file (infotext[0]) is not currently used, but we
// suggest supplying a name it in case it eventually is used.

char *infotext[17] =
{
	"Water V1.0",
	"Octaves",
	"X Size", "Y Size", "Z Size",
	"", "",
	"", "", "",
	"", "", "",
	"", "", "", "",
};

// infoflags[] is an array of TXTF_ (texture flags) for the data
// fields of the texture requester.  The the TXTF flags are as
// follows:
//      Bit 0 - alter the red gun in the requester color chip
//      Bit 1 - alter the green gun in the requester color chip
//      Bit 2 - alter the blue gun in the requester color chip
//      Bit 3 - auto-scale this data field when object is scaled
//      Bits 4 thru 7 - reserved

UBYTE   infoflags[16] =
{
    0, 0, 0,
    0, 0, 0,
    0, 0, 0,
    0, 0, 0,
    0, 0, 0, 0,
};

// fparams[] is an array of floats that are the initial defaults
// in the texture requester.  The values in this array can be
// modified by the user and are passed to the texture code by
// the floating point version of Imagine's renderer.

FLOAT   fparams[16] =
{
    3.0, 1.0, 1.0, 1.0,
    0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0,
};

// ftform[] is an array of floats that represent the initial TFORM data
// (size and position) of the texture axis.  The values in this array can
// be modified by the user (via edit axis) and are passed to the texture
// code by the floating point version of Imagine's renderer.

FLOAT   ftform[15] =
{
    0.0, 0.0, 0.0,      // position vector
    1.0, 0.0, 0.0,      // X axis alignment vector
    0.0, 1.0, 0.0,      // Y axis alignment vector
    0.0, 0.0, 1.0,      // Z axis alignment vector
    32.0, 32.0, 32.0,   // size of each axis
};

// this ttable{} structure is defined earlier and initialized here.

TTABLE ttable =
{
    TXT_VERS,       /* version identifier - this contstant must be used */
    NULL,
    NULL,
    NULL,
    (UBYTE **)infotext,
    infoflags,
};

/*************
 * FUNCTION:		texture_init
 * DESCRIPTION:	This is the texture_init() module for the textures.  This is the entry
 * module through which Imagine loads and calls the texture code.
 * texture_init() is called with a version number and a flag representing
 * whether this texture is being called from a floating point version or an
 * integer version of Imagine.  On the Amiga, these two (WORD) arguments
 * are packed into and passed as a single LONG which, in turn, is parsed
 * into the two arguments and interpreted within texture_init(). If all
 * goes well, texture_init() then initializes the ttable{} structure
 * (defined above) with the proper info and returns a pointer, for the
 * ttable{} structure, back to Imagine.
 * INPUT:			arg0			flags
 * OUTPUT:			pointer to texture, NULL if non found
 *************/
#ifdef __AMIGA__
// Amiga version
TTABLE *texture_init(LONG arg0)
{
	WORD vers, fp;

	SysBase = (*((struct ExecBase **) 4));
	vers = arg0 >> 16;      // parse out the two arguments
	fp = arg0 & 0xffff;
#else
// PC version
TTABLE *texture_init(int vers, int fp)
{
#endif
	if(vers != 0x60 || !fp)	// look for wrong version number and integer version
		return 0L;

	// called from the floating point version
	ttable.work = fwork;
	ttable.cleanup = CleanupNoise;
	ttable.params = (APTR)fparams;
	ttable.tform = (APTR)ftform;

	if(!InitNoise())
		return 0L;

	return &ttable;
}

#ifdef __SASC
	void __stdargs _XCEXIT(long a) { }
#endif

/*************
 * FUNCTION:		fwork
 * DESCRIPTION:	this is the floating point work function
 * INPUT:			params	pointer to user definable numbers in requester
 *						pt			pointer to patch structure - defined above
 *						v			hit position  -  relative to texture axis
 *						t			info about texture axis (TFORM array - 15 floats)
 * OUTPUT:			pointer to texture, NULL if non found
 *************/
void fwork(FRACT *params, PATCH *pt, VECTOR *v, FRACT *t)
{
	VECTOR *norm, offset;
	float d;

	v->x /= t[12];
	v->y /= t[13];
	v->z /= t[14];

	VfBm(v, 3.f, 2.f, (int)params[0], &offset);

	norm = &pt->ptc_nor;
	norm->x += offset.x * params[1];
	norm->y += offset.y * params[2];
	norm->z += offset.z * params[3];

	// Normalize
	d = sqrt(norm->x*norm->x + norm->y*norm->y + norm->z*norm->z);
	if (d == 0.f)
		return;
	d = 1.f/d;
	norm->x *= d;
	norm->y *= d;
	norm->z *= d;
}
