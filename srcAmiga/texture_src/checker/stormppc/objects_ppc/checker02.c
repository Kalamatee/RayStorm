// Stub functions for object "SoftDisk:User/mcpp3/work/octree/texture_src/checker/stormppc/objects_ppc/checker.o"
// Generated by genMixBinStub 1.0 for StormC
// � 1997 HAAGE & PARTNER GmbH

// DO NOT EDIT

#ifndef __PPC__
#include <libraries/powerpc.h>
#include <pragma/powerpc_lib.h>
#endif // __PPC__

#ifndef __PPC__
extern "ASM" void _PPCStub__fwork(void);
extern "ASM" void _fwork(void *arg1,void *arg2,void *arg3,void *arg4)
{
	struct PPCArgs ppc = { };
	static void (*_PPCData__fwork)(void) = _PPCStub__fwork;
	ppc.PP_Code = _PPCData__fwork;
	long args[4];
	args[0] = (long) arg1;
	args[1] = (long) arg2;
	args[2] = (long) arg3;
	args[3] = (long) arg4;
	ppc.PP_Regs[0] = (ULONG) args;
	RunPPC(&ppc);
}
#else // __PPC__
extern "ASM" void _fwork(void *arg1,void *arg2,void *arg3,void *arg4);
extern "ASM" void __saveds _PPCStub__fwork(long *args)
{
	_fwork(
		(void *) args[0],
		(void *) args[1],
		(void *) args[2],
		(void *) args[3]
	);
}
#endif // __PPC__

