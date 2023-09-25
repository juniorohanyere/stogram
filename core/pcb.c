#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "pcb.h"
#include "child.h"
#include "externs.h"
#include "indicator.h"

/**
 * init_pcb - initializes the process control block
 *
 * Return: return nothing
*/

void init_process(void)
{
	pcb = malloc(sizeof(PCB) * PCB_SIZE);
	if (pcb == NULL)
	{
		pcb->_errno = MALLOC_ERR;
		return;
	}

	for (i = 1; i < PCB_SIZE; i++)
	{
		pcb[i]._errno = OK;
		pcb[i].state = RUNNING;

		pcb[i].pid = i;
		pcb[i].ppid = 0;
		pcb[i].prio = 0;
		pcb[i].pc = 0;

		pcb[i].name = NULL;
		pcb[i].reg = NULL;

		pcb[i].meminfo = meminfo;
		pcb[i].fdt = fdt;
	}
}

/**
 * create_process - creates a new process
 *
 * @ppid: the parent process id
 * @prio: the priority
 * @pc: the program counter
 * @_errno: indicator for error
 * @state: the process state (idle, running, ready, bocked, terminated, etc)
 * @name: the process name
 * @reg: the process cpu registers
 *
 * Return: return the process id (pid)
*/

int32_t create_process(uint16_t ppid, uint16_t prio, uint16_t pc,
	state_t state, char *name, char *reg)
{
	int32_t i;

	for (i = 1; i < PCB_SIZE; i++)
	{
		if (pcb[i].name == NULL)
		{
			/* empty slot found */
			pcb[i]._errno = OK;
			pcb[i].state = state;

			pcb[i].pid = pid;
			pcb[i].ppid = ppid;
			pcb[i].prio = prio;
			pcb[i].pc = pc;

			pcb[i].name = strdup(name);
			pcb[i].reg = strdup(reg);

			add_child(ppid, i);

			return (i);	/* return i as the pid */
		}
	}
	pcb->_errno = PCB_ERR;
	return (-1);	/* when the process table is full */
}
