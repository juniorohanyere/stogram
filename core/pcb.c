#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "pcb.h"
#include "child.h"
#include "externs.h"

/**
 * init_pcb - initializes the process control block
 *
 * Return: return nothing
*/

void init_pcb(void)
{
	pcb = malloc(sizeof(PCB) * PCB_SIZE);
	if (pcb == NULL)
		return;

	for (i = 1; i < PCB_SIZE; i++)
	{
		pcb[i].status = OK;
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
 * @status: the exit status of the process
 * @state: the process state (idle, running, ready, bocked, terminated, etc)
 * @name: the process name
 * @reg: the process cpu registers
 *
 * Return: return the process id (pid)
*/

int32_t create_process(uint16_t ppid, uint16_t prio, uint16_t pc,
	status_t status, state_t state, char *name, char *reg)
{
	int32_t i;

	for (i = 1; i < PCB_SIZE; i++)
	{
		if (pcb[i].name == NULL)
		{
			/* empty slot found */
			pcb[i].status = status;
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
	return (-1);	/* when the process table is full */
}
