#include <stdio.h>
#include <stdlib.h>

#include "pcb.h"
#include "skernel.h"
#include "indicator.h"
#include "fdt.h"
#include "child.h"

/**
 * init_system - initializes the stogram chat system by setting up necessary
 *		 data structures and memory blocks
 *
 * @pcb: process control block
 *
 * Description: creates the first pid as 0, this pid serves as a place holder
 *		for all process that are going to be spawned directly or
 *		indirectly. It then transfers control to pid 1 which is the
 *		systemd process.
 *
 * Return: return nothing
*/

void init_system(PCB *pcb)	/* swapper */
{
	uint16_t bootd;

	init_process(pcb);

	if (pcb->status == MALLOC_ERR)
	{
		/* malloc_error(); */
		/* repeated beeping sound while on hang */
		return;
	}

	bootd = create_process(pcb, 0, 0, "bootd");	/* place holder */
	if (pcb->status == MALLOC_ERR)
	{
		/* malloc_error(); */
		/* repeated beeping sound while on hang */
		return;
	}
	printf("process created successfully\n");
	system_daemon(pcb, bootd);
}

/**
 * system_daemon - responsible for initiating services, targets, etc
 *
 * @pcb: process control block
 *
 * @ppid: the parent process id, this should be the pid 0
 *
 * Return: return nothing
*/

void system_daemon(PCB *pcb, uint16_t ppid)
{
	uint16_t systemd;

	/* start systemd process, pid 1 is specially reserved for it */
	systemd = create_process(pcb, ppid, 1, "systemd");
	printf("process created successfully\n");

	/* initiate services, mounts, protocols, slices, etc */
	/* init_presets(); */
	/* init_services(systemd); */
	/*
	 * init_mounts();
	 * init_protocols();
	 * init_slices();
	 * init_scopes();
	 * init_targets();
	 * init_sockets();
	 * init_timers();
	 * init_automodes();
	 * init_swaps()
	 * init_paths()
	 * init_specials()
	*/
	pcb[systemd].state = IDLE;
}
