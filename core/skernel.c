#include <stdio.h>

#include "fdt.h"
#include "pcb.h"
#include "externs.h"
#include "skernel.h"
#include "indicator.h"

/**
 * skernel - entry point for the Stogram Kernel
 *
 * Description: pcb->status is always used to handle error/exit status
 *		always check the error/exit status returned by a function in
 *		description of the function, to know how to handle errors when
 *		making use of the function
 *
 * Return: always return 0 for now
*/

int skernel(void)
{
	init_system();

	return (0);
}

/**
 * init_system - initializes the stogram chat system by setting up necessary
 *		 data structures and memory blocks
 *
 * Description: creates the first pid as 0, this pid serves as a place holder
 *		for all process that are going to be spawned directly or
 *		indirectly. It then transfers control to pid 1 which is the
 *		systemd process.
 *
 * Return: return nothing
*/

void init_system(void)	/* swapper */
{
	uint16_t initd;

	init_process();

	if (pcb->status == MALLOC_ERR)
	{
		/* malloc_error(); */
		/* repeated beeping sound while on hang */
		return;
	}

	initd = create_process(0, 0, "initd");	/* place holder */
	if (pcb->status == MALLOC_ERR)
	{
		/* malloc_error(); */
		/* repeated beeping sound while on hang */
		return;
	}

	system_daemon(initd);
}

/**
 * system_daemon - responsible for initiating services, targets, etc
 *
 * @ppid: the parent process id, this should be the pid 0
 *
 * Return: return nothing
*/

void system_daemon(uint16_t ppid)
{
	uint16_t systemd;

	/* start systemd process, pid 1 is specially reserved for it */
	systemd = create_process(ppid, 1, "systemd");

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
