;***************
;* MODUL:         RayStorm
;* NAME:          raystorm.library.asm
;* DESCRIPTION:   RayStorm run-time library source code
;* AUTHORS:       Andreas Heumann, Mike Hesser
;* HISTORY:
;*    DATE     NAME  COMMENT
;*    03.06.96 ah    initial release
;*    04.11.96 ah    added rsiCreateFlare and rsiCreateStar
;*    25.11.96 ah    added rsiSetFlare and rsiSetStar
;*    05.12.96 ah    added statistic functions
;*    10.01.97 ah    added box functions
;*    10.01.97 ah    added CSG functions
;*    07.03.97 ah    added rsiCreateMesh
;*    14.03.97 ah    added hyper texture
;*    19.03.97 ah    added cylinder functions
;*    22.03.97 ah    added SOR functions
;*    23.03.97 ah    added cone functions
;***************

CALLSYS MACRO           ; call a library via A6 without having to see _LVO
		  JSR     _LVO\1(A6)
		  ENDM

VERSION  EQU   2
REVISION EQU   0

VSTRING MACRO
					 dc.b    'RayStorm 2.0 (22.06.97)',13,10,0
		  ENDM

	SECTION   code

	NOLIST
	INCLUDE "exec/types.i"
	INCLUDE "exec/initializers.i"
	INCLUDE "exec/libraries.i"
	INCLUDE "exec/lists.i"
	INCLUDE "exec/alerts.i"
	INCLUDE "exec/resident.i"
	INCLUDE "libraries/dos.i"

	INCLUDE "raystormbase.i"

	LIST

	XDEF   InitTable                    ;------ These don't have to be external but it helps
	XDEF   Open                         ;------ some debuggers to have them globally visible
	XDEF   Close
	XDEF   Expunge
	XDEF   Null
	XDEF   LibName

	XREF  _AbsExecBase
	XREF  _DosBase

	XREF  _InitModules
	XREF  _CleanupModules

	XREF  _LVOOpenLibrary
	XREF  _LVOCloseLibrary
	XREF  _LVOAlert
	XREF  _LVOFreeMem
	XREF  _LVORemove

	XREF  _rsiSetCooperateCB
	XREF  _rsiSetCheckCancelCB
	XREF  _rsiSetLogCB
	XREF  _rsiSetUpdateStatusCB

	XREF  _rsiInit
	XREF  _rsiExit
	XREF  _rsiGetErrorMsg
	XREF  _rsiCleanup
;  XREF  _rsiGetStats
;  XREF  _rsiGetStatDescription

	XREF  _rsiRender
	XREF  _rsiSetOctreeDepth
	XREF  _rsiSetRenderField
	XREF  _rsiSetAntialias
	XREF  _rsiSetDistribution
	XREF  _rsiSetRandomJitter
	XREF  _rsiSetWorld
	XREF  _rsiSetCamera
	XREF  _rsiSetScreen
	XREF  _rsiSetBrushPath
	XREF  _rsiSetTexturePath
	XREF  _rsiSetObjectPath
	XREF  _rsiSavePicture

	XREF  _rsiCreatePointLight
	XREF  _rsiSetPointLight
	XREF  _rsiCreateSpotLight
	XREF  _rsiSetSpotLight
	XREF  _rsiCreateFlare
	XREF  _rsiSetFlare
	XREF  _rsiCreateStar
	XREF  _rsiSetStar
	XREF  _rsiCreateSphere
	XREF  _rsiSetSphere
	XREF  _rsiCreateTriangle
	XREF  _rsiCreateMesh
	XREF  _rsiCreatePlane
	XREF  _rsiSetPlane
	XREF  _rsiCreateCSG
	XREF  _rsiSetCSG
	XREF  _rsiLoadObject
	XREF  _rsiCreateBox
	XREF  _rsiSetBox
	XREF  _rsiCreateCylinder
	XREF  _rsiSetCylinder
	XREF  _rsiCreateSOR
	XREF  _rsiSetSOR
	XREF  _rsiCreateCone
	XREF  _rsiSetCone

	XREF  _rsiCreateSurface
	XREF  _rsiSetSurface
	XREF  _rsiAddTexture
	XREF  _rsiSetTexture
	XREF  _rsiAddHyperTexture
	XREF  _rsiSetHyperTexture
	XREF  _rsiAddBrush
	XREF  _rsiSetBrush

	XREF  _rsiCreateActor
	XREF  _rsiSetActor
	XREF  _rsiPosition
	XREF  _rsiAlignment
	XREF  _rsiSize


	; The first executable location.  This should return an error in case someone tried to
	; run you as a program (instead of loading you as a library).
Start:
	MOVEQ   #-1,d0
	rts

;------------------------------------------------------------------------------------------
; A romtag structure.  Both "exec" and "ramlib" look for this structure to discover magic
; constants about you (such as where to start running you from...).  The include file
; sample_rev.i (created by hand or preferable with the developer tool ``bumprev''
; resolves the VERSION, REVISION, and VSTRING.
;------------------------------------------------------------------------------------------
	; Few people will need a priority and should leave it at zero.  The RT_PRI field is used
	; in configuring the ROMs.  Use "mods" from wack to look at other romtags in the system.
MYPRI   EQU   0

RomTag:
					;STRUCTURE RT,0
	  DC.W    RTC_MATCHWORD      ; UWORD RT_MATCHWORD
	  DC.L    RomTag             ; APTR  RT_MATCHTAG
	  DC.L    EndCode            ; APTR  RT_ENDSKIP
	  DC.B    RTF_AUTOINIT       ; UBYTE RT_FLAGS
	  DC.B    VERSION            ; UBYTE RT_VERSION
	  DC.B    NT_LIBRARY         ; UBYTE RT_TYPE
	  DC.B    MYPRI              ; BYTE  RT_PRI
	  DC.L    LibName            ; APTR  RT_NAME
	  DC.L    IDString           ; APTR  RT_IDSTRING
	  DC.L    InitTable          ; APTR  RT_INIT  table for InitResident()

	; this is the name that the library will have
LibName:   RAYSTORMNAME
IDString:  VSTRING

dosName:   DOSNAME

	; force word alignment
	ds.w   0

	; The romtag specified that we were "RTF_AUTOINIT".  This means that the RT_INIT
	; structure member points to one of these tables below.  If the AUTOINIT bit was not
	; set then RT_INIT would point to a routine to run.

InitTable:
	DC.L   RayStormBase_SIZEOF ; size of library base data space
	DC.L   funcTable         ; pointer to function initializers
	DC.L   dataTable         ; pointer to data initializers
	DC.L   initRoutine       ; routine to run


funcTable:

	;------ standard system routines
	dc.l   Open
	dc.l   Close
	dc.l   Expunge
	dc.l   Null

	;------ my libraries definitions
	dc.l  _rsiSetCooperateCB
	dc.l  _rsiSetCheckCancelCB
	dc.l  _rsiSetLogCB
	dc.l  _rsiSetUpdateStatusCB

	dc.l  _rsiInit
	dc.l  _rsiExit
	dc.l  _rsiGetErrorMsg
	dc.l  _rsiCleanup

	; raytracing controling commands
	dc.l  _rsiRender
	dc.l  _rsiSetOctreeDepth
	dc.l  _rsiSetRenderField
	dc.l  _rsiSetAntialias
	dc.l  _rsiSetDistribution
	dc.l  _rsiSetRandomJitter
	dc.l  _rsiSetWorld
	dc.l  _rsiSetCamera
	dc.l  _rsiSetScreen
	dc.l  _rsiSetBrushPath
	dc.l  _rsiSetTexturePath
	dc.l  _rsiSetObjectPath
	dc.l  _rsiSavePicture

	; commands for creating objects
	dc.l  _rsiCreatePointLight
	dc.l  _rsiSetPointLight
	dc.l  _rsiCreateSpotLight
	dc.l  _rsiSetSpotLight
	dc.l  _rsiCreateFlare
	dc.l  _rsiSetFlare
	dc.l  _rsiCreateStar
	dc.l  _rsiSetStar
	dc.l  _rsiCreateSphere
	dc.l  _rsiSetSphere
	dc.l  _rsiCreateTriangle
	dc.l  _rsiCreateMesh
	dc.l  _rsiCreatePlane
	dc.l  _rsiSetPlane
	dc.l  _rsiCreateCSG
	dc.l  _rsiSetCSG
	dc.l  _rsiLoadObject
	dc.l  _rsiCreateBox
	dc.l  _rsiSetBox
	dc.l  _rsiCreateCylinder
	dc.l  _rsiSetCylinder
	dc.l  _rsiCreateSOR
	dc.l  _rsiSetSOR
	dc.l  _rsiCreateCone
	dc.l  _rsiSetCone

	; SURFACE relating commands
	dc.l  _rsiCreateSurface
	dc.l  _rsiSetSurface
	dc.l  _rsiAddTexture
	dc.l  _rsiSetTexture
	dc.l  _rsiAddHyperTexture
	dc.l  _rsiSetHyperTexture
	dc.l  _rsiAddBrush
	dc.l  _rsiSetBrush

	; ACTOR relating commands
	dc.l  _rsiCreateActor
	dc.l  _rsiSetActor
	dc.l  _rsiPosition
	dc.l  _rsiAlignment
	dc.l  _rsiSize

;  dc.l  _rsiGetStats
;  dc.l  _rsiGetStatDescription

	;------ function table end marker
	dc.l   -1


	; The data table initializes static data structures.  The format is specified in
	; exec/InitStruct routine's manual pages.  The INITBYTE/INITWORD/INITLONG routines are
	; in the file "exec/initializers.i".  The first argument is the offset from the library
	; base for this byte/word/long.  The second argument is the value to put in that cell.
	; The table is null terminated.
	; NOTE - LN_TYPE below is a correction - old example had LH_TYPE.

dataTable:
		  INITBYTE        LN_TYPE,NT_LIBRARY
		  INITLONG        LN_NAME,LibName
		  INITBYTE        LIB_FLAGS,LIBF_SUMUSED!LIBF_CHANGED
		  INITWORD        LIB_VERSION,VERSION
		  INITWORD        LIB_REVISION,REVISION
		  INITLONG        LIB_IDSTRING,IDString
		  DC.L   0

	; This routine gets called after the library has been allocated.  The library pointer is
	; in D0.  The segment list is in A0.  If it returns non-zero then the library will be
	; linked into the library list.

initRoutine:

	;------ get the library pointer into a convenient A register
	move.l   a5,-(sp)
	move.l   d0,a5

	;------ save a pointer to exec
	move.l   a6,sb_SysLib(a5)

	;------ save a pointer to our loaded code
	move.l   a0,sb_SegList(a5)

	;------ open the dos library
	lea      dosName(pc),a1
	moveq    #0,d0
	CALLSYS  OpenLibrary

	move.l   d0,sb_DosLib(a5)
	move.l   d0,_DosBase
	bne.s    1$

	;------ can't open the dos!  what gives
	ALERT   AG_OpenLib!AO_DOSLib

1$:
	;------ now build the static data that we need
	;
	; put your initialization here...
	;

	move.l   a5,-(sp)
	jsr      _InitModules
	move.l   (sp)+,a5

	move.l   a5,d0
	move.l   (sp)+,a5
	rts

;------------------------------------------------------------------------------------------
; here begins the system interface commands.  When the user calls OpenLibrary/CloseLibrary/
; RemoveLibrary, this eventually gets translated into a call to the following routines
; (Open/Close/Expunge).  Exec has already put our library pointer in A6 for us.  Exec has
; turned off task switching while in these routines (via Forbid/Permit), so we should not
; take too long in them.
;------------------------------------------------------------------------------------------

	; Open returns the library pointer in d0 if the open was successful.  If the open failed
	; then null is returned.  It might fail if we allocated memory on each open, or if only
	; open application could have the library open at a time...

Open:      ; ( libptr:a6, version:d0 )

	;------ only one a time can open this library
	cmp.w    #0,LIB_OPENCNT(a6)
	beq.b    do_open

	moveq    #0,d0
	rts

do_open:
	;------ mark us as having another opener
	addq.w   #1,LIB_OPENCNT(a6)

	;------ prevent delayed expunges
	bclr   #LIBB_DELEXP,sb_Flags(a6)

	move.l   a6,d0
	rts

	; There are two different things that might be returned from the Close routine.  If the
	; library is no longer open and there is a delayed expunge then Close should return the
	; segment list (as given to Init).  Otherwise close should return NULL.

Close:      ; ( libptr:a6 )

	;------ set the return value
	moveq    #0,d0

	;------ mark us as having one fewer openers
	subq.w   #1,LIB_OPENCNT(a6)

	;------ see if there is anyone left with us open
	bne.s   1$

	;------ see if we have a delayed expunge pending
	btst   #LIBB_DELEXP,sb_Flags(a6)
	beq.s   1$

	;------ do the expunge
	bsr   Expunge
1$:
	rts

	; There are two different things that might be returned from the Expunge routine.  If
	; the library is no longer open then Expunge should return the segment list (as given
	; to Init).  Otherwise Expunge should set the delayed expunge flag and return NULL.
	;
	; One other important note: because Expunge is called from the memory allocator, it may
	; NEVER Wait() or otherwise take long time to complete.

Expunge:   ; ( libptr: a6 )

	movem.l   d2/a5/a6,-(sp)
	move.l   a6,a5
	move.l   sb_SysLib(a5),a6

	;------ see if anyone has us open
	tst.w   LIB_OPENCNT(a5)
	beq   1$

	;------ it is still open.  set the delayed expunge flag
	bset   #LIBB_DELEXP,sb_Flags(a5)
	moveq    #0,d0
	bra.s   Expunge_End

1$:
	;------ go ahead and get rid of us.  Store our seglist in d2
	move.l   sb_SegList(a5),d2

	;------ unlink from library list
	move.l   a5,a1
	CALLSYS   Remove

	;
	; device specific closings here...
	;

	jsr      _CleanupModules

	;------ close the dos library
	move.l   sb_DosLib(a5),a1
	CALLSYS   CloseLibrary

	;------ free our memory
	moveq    #0,d0
	move.l   a5,a1
	move.w   LIB_NEGSIZE(a5),d0

	sub.l   d0,a1
	add.w   LIB_POSSIZE(a5),d0

	CALLSYS   FreeMem

	;------ set up our return value
	move.l   d2,d0

Expunge_End:
	movem.l   (sp)+,d2/a5/a6
	rts

Null:
	moveq    #0,d0
	rts

CINTERF  macro
\1:
	IFGT     NARG-9
		move.l   \a,-(sp)
	ENDC
	IFGT     NARG-8
		move.l   \9,-(sp)
	ENDC
	IFGT     NARG-7
		move.l   \8,-(sp)
	ENDC
	IFGT     NARG-6
		move.l   \7,-(sp)
	ENDC
	IFGT     NARG-5
		move.l   \6,-(sp)
	ENDC
	IFGT     NARG-4
		move.l   \5,-(sp)
	ENDC
	IFGT     NARG-3
		move.l   \4,-(sp)
	ENDC
	IFGT     NARG-2
		move.l   \3,-(sp)
	ENDC
	jsr      _\1
	IFGT     NARG-1
		adda.l   #\2,sp
	ENDC
	rts

	endm

	; EndCode is a marker that show the end of your code.  Make sure it does not span
	; sections nor is before the rom tag in memory!  It is ok to put it right after the ROM
	; tag--that way you are always safe.  I put it here because it happens to be the "right"
	; thing to do, and I know that it is safe in this case.
EndCode:

	END

