/***************
 * NAME:          worldanim.cpp
 * VERSION:       1.0 10.08.1995
 * DESCRIPTION:   Example program for RayStorm
 *						this program has been compiled with Maxon C++ 3.0
 *	AUTHORS:			Andreas Heumann, Mike Hesser
 * BUGS:          none
 * TO DO:         
 * HISTORY:       DATE		NAME	COMMENT
 *						10.08.95	ah		first release
 ***************/

#include <exec/memory.h>
#include <rexx/storage.h>
#include <rexx/rxslib.h>
#include <exec/types.h>

#include <pragma/exec_lib.h>
#include <pragma/rexxsyslib_lib.h>

#include <fstream.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

struct Library *RexxSysBase = NULL;
static struct MsgPort *HostPort;
static struct MsgPort *ReplyPort = NULL;

static int msgs = 0;		// remaining messages

/*************
 * FUNCTION:		cleanup
 * VERSION:			1.0 08.05.1995
 * DESCRIPTION:	close libs ...
 * INPUT:			none
 * OUTPUT:			none
 * HISTORY:       DATE		NAME		COMMENT
 *						08.05.95	ah			first release
 *************/
void cleanup()
{
	struct RexxMsg *RexxMessage;

	if(ReplyPort)
	{
		// free messages
		while(msgs)
		{
			// Wait for message
			WaitPort(ReplyPort);
			// get messages
			while(RexxMessage = (struct RexxMsg*)GetMsg(ReplyPort))
			{
				// Remove Rexx message
				ClearRexxMsg(RexxMessage,1);
				DeleteRexxMsg(RexxMessage);
				msgs--;
			}
		}
		// Free reply port signal bit
		FreeSignal(ReplyPort->mp_SigBit);
		// Free the replyport itself
		FreeMem(ReplyPort,sizeof(struct MsgPort));
	}
	if (RexxSysBase)
		CloseLibrary(RexxSysBase);
	exit(0);
}

/*************
 * FUNCTION:		SendRexxMsg
 * VERSION:			1.0 08.05.1995
 * DESCRIPTION:	Sends a single command to Rexx host
 * INPUT:			HostPort		pointer to host message port
 *						SingleMsg	message to send
 * OUTPUT:			none
 * HISTORY:       DATE		NAME		COMMENT
 *						08.05.95	ah			first release
 *************/
void SendRexxMsg(struct MsgPort *HostPort, char *SingleMsg)
{
	struct RexxMsg *RexxMessage;

	// free previous messages
	while(RexxMessage = (struct RexxMsg*)GetMsg(ReplyPort))
	{
		// Remove Rexx message
		if(RexxMessage->rm_Result1)
		   cout << RexxMessage->rm_Args[0] << "-> Error: " << RexxMessage->rm_Result1 << "\n";
		ClearRexxMsg(RexxMessage,1);
		DeleteRexxMsg(RexxMessage);
		msgs--;
	}

	// Valid pointers given?
	if(HostPort && SingleMsg)
	{
		// Create a Rexx message
		RexxMessage = (struct RexxMsg *)CreateRexxMsg(ReplyPort,"",NULL);
		if(RexxMessage)
		{
			RexxMessage->rm_Args[0] = CreateArgstring(SingleMsg, strlen(SingleMsg));
			RexxMessage->rm_Action = RXFF_RESULT;

			// Send packet
			PutMsg(HostPort,(struct Message *)RexxMessage);
			msgs++;
			WaitPort(ReplyPort);
			RexxMessage = (struct RexxMsg*)GetMsg(ReplyPort);
			// Remove Rexx message
			if(RexxMessage->rm_Result1)
			   cout << RexxMessage->rm_Args[0] << "-> Error: " << RexxMessage->rm_Result1 << "\n";
			ClearRexxMsg(RexxMessage,1);
			DeleteRexxMsg(RexxMessage);
			msgs--;
		}
	}
}

/*************
 * FUNCTION:		Init
 * VERSION:			1.0 08.05.1995
 * DESCRIPTION:	Open libs, init ports
 * INPUT:			none
 * OUTPUT:			none
 * HISTORY:       DATE		NAME		COMMENT
 *						08.05.95	ah			first release
 *************/
void Init()
{
	// is raystrom already active ?
	HostPort = (struct MsgPort *)FindPort("RAYSTORM");
	if(!HostPort)
	{
		cout << "Raystorm is not running please start it\n";
		cleanup();
	}
	// Allocate a reply port
	ReplyPort = (struct MsgPort *)AllocMem(sizeof(struct MsgPort),MEMF_PUBLIC | MEMF_CLEAR);
	if(ReplyPort)
	{
		ReplyPort->mp_SigBit = AllocSignal(-1);
		if(ReplyPort->mp_SigBit != -1)
		{
			ReplyPort->mp_Node.ln_Type	= NT_MSGPORT;
			ReplyPort->mp_Flags			= PA_SIGNAL;
			ReplyPort->mp_SigTask		= FindTask(NULL);

			ReplyPort->mp_MsgList.lh_Head = (struct Node *)&ReplyPort->mp_MsgList.lh_Tail;
			ReplyPort->mp_MsgList.lh_Tail = 0;
			ReplyPort->mp_MsgList.lh_TailPred = (struct Node *)&ReplyPort->mp_MsgList.lh_Head;
		}
	}

	// Open rexxsyslib library.
	RexxSysBase = OpenLibrary("rexxsyslib.library",0L);
	if (!RexxSysBase)
	{
		cout << "Can't open rexxsyslib.library\n";
		cleanup();
	}
}

void main(int argc, char *argv[])
{
	float f;
	int i, pics;
	char buffer[256];

	// Parse arguments
	if(argc != 2)
	{
		cout << "Worldanim V1.0 1995 by Andreas Heumann\n";
		cout << "Usage: worldanim picnum\n";
		cout << "   picnum - amount of pictures to create\n";
		cleanup();
	}
	sscanf(argv[1],"%d",&pics);
	if(pics<2)
	{
		cout << "I need at least two pictures to create.\n";
		cleanup();
	}

	Init();

	i=1;
	for(f=0; f<360; f+=360/pics)
	{
		SendRexxMsg(HostPort, "SETSCREEN 160 128");
		SendRexxMsg(HostPort, "SETWORLD [0,0,0] [100,100,100]");
		SendRexxMsg(HostPort, "SETCAMERA <0,0,4> <0,0,0> <0,1,0> 56.25 45");
		SendRexxMsg(HostPort, "POINTLIGHT <5,5,10>");
		SendRexxMsg(HostPort, "NEWSURFACE EARTH");
		sprintf(buffer, "BRUSH /brushes/earth.iff COLOR WRAPXY <0,0,0> <0,%d,0> <.1,.1,.1>", int(f));
		SendRexxMsg(HostPort, buffer);
		SendRexxMsg(HostPort, "SPHERE EARTH <0,0,0> 1");
		SendRexxMsg(HostPort, "STARTRENDER QUICK");
		sprintf(buffer, "SAVEPIC pics/world.%04d", i);
		SendRexxMsg(HostPort, buffer);
		SendRexxMsg(HostPort, "CLEANUP");
		i++;
	}

	cleanup();
} 