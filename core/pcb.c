#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "pcb.h"
#include "child.h"
#include "indicator.h"
#include "fdt.h"

/**
 * init_process - initializes the process control block
 *
 * @pcb: process control block
 *
 * Description: the maximum number of processes is 1024 * 10 => 10240
 *
 * Return: return nothing
*/

void init_process(PCB *pcb)
{
	int i;

	for (i = 0; i < PCB_SIZE; i++)
	{
		/* fill children PIDs with zeros */
		pcb[i].fdt = init_fdt(pcb);
		pcb[i].children = calloc(sizeof(int), PCB_SIZE);
		if (pcb->status == MALLOC_ERR)
		{
			pcb->status = MALLOC_ERR;
			return;
		}

		if (pcb[i].children == NULL)
		{
			pcb->status = MALLOC_ERR;

			for (i = 0; i < PCB_SIZE; i++)
				destroy_fdt(pcb, i);

			return;
		}

		pcb->status = OK;
		pcb[i].ppid = 0;
		pcb[i].prio = 0;
		pcb[i].state = RUNNING;
		pcb[i].name = NULL;
		/* pcb[i].meminfo = meminfo; */
		/* pcb[i].pc = 0; */
		/* pcb[i].reg = NULL; */
	}
}

/**
 * create_process - creates a new process
 *
 * @pcb: process control block
 * @ppid: the parent process id
 * @prio: the priority
 * @name: the process name
 *
 * Description: @name must not be NULL, else it will be taken as malloc error
 *
 * Return: return the process id (pid)
*/

uint16_t create_process(PCB *pcb, uint16_t ppid, uint16_t prio, char *name)
{
	uint16_t i;	/* this is the pid */

	for (i = 0; i < PCB_SIZE; i++)
	{
		if (pcb[i].name == NULL)
		{
			/* empty slot found */
			pcb[i].name = strdup(name);
			if (pcb[i].name == NULL)
			{
				pcb->status = MALLOC_ERR;
				return (i);
			}

			pcb->status = OK;
			pcb[i].ppid = ppid;
			pcb[i].prio = prio;
			/* pcb[i].pc = pc; */
			/* pcb[i].reg = reg; */

			add_child(pcb, ppid, i);

			return (i);	/* return i as the pid */
		}
	}
	/* when the process table is full */
	pcb->status = PCB_FULL;
	return (0);
}

/**
 * destroy_process - frees memory associated with a processes
 *
 * @pcb: process control block
 * @pid: the pid of the process to destroy
 *
 * Return: return nothing
*/

void destroy_process(PCB *pcb, uint16_t pid)
{
	free(pcb[pid].name);

	free(pcb[pid].children);
	destroy_fdt(pcb, pid);
}
