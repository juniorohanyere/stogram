#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "pcb.h"

/**
 * create_pcb - creates a new pcb_t type
 *
 * @pid: the process id
 * @ppid: the parent process id
 * @prio: the priority
 * @pc: the program counter
 * @status: the exit status of the process
 * @state: the process state (idle, running, ready, bocked, terminated, etc)
 * @name: the process name
 * @reg: the process cpu registers
 * @meminfo: the memory information
 * @fdt: file descritor table
 * @tcb: the thread control block (TCB)
 * @child: the child process(es), if any
 *
 * Description: the maximum number of processes is uint16_t (65,535)
 *
 * Return: return pcb_t type with all necessary data set on success
 *	   return pcb_t type setting errno as the error status on failure
*/

PCB **create_pcb(uint16_t pid, uint16_t ppid, uint16_t prio, uint16_t pc,
	status_t status, state_t state, char *name, char *reg,
	meminfo_t *meminfo, FDT *fdt, TCB *tcb, PCB *child)
{
	PCB *pcb;

	pcb = malloc(sizeof(PCB));
	if (pcb == NULL)
	{
		pcb->errno = ERR_M;

		return (pcb);
	}

	pcb->errno = OK;
	pcb->status = status;
	pcb->state = state;

	pcb->pid = pid;
	pcb->ppid = ppid;
	pcb->prio = prio;
	pcb->pc = pc;

	pcb->name = strdup(name);
	pcb->reg = strdup(reg);

	pcb->meminfo = malloc(sizeof(meminfo_t));
	pcb->fdt = malloc(sizeof(FDT));
	pcb->child = malloc(sizeof(PCB));

	if (pcb->pname == NULL || pcb->preg == NULL || pcb->cmd == NULL ||
		pcb->meminfo == NULL || pcb->fdt == NULL || pcb->child == NULL)
	{
		pcb->errno = ERR_M;

		return (pcb);
	}

	pcb->meminfo = meminfo;
	pcb->fdt = fdt;
	pcb->child = child;

	return (pcb);
}

/*
 * char **pcb_info(pcb_t *pcb)
 * {
 *	char **info;
 *
 *	info = malloc(sizeof(char *) * 11);
 *	if (pcb == NULL || info == NULL)
 *		return (NULL);
 *
 *	strcpy(info[0], (char *)&pcb->id);
 *	strcpy(info[1], (char *)&pcb->pid);
 *	strcpy(info[2], (char *)&pcb->ppid);
 *	strcpy(info[3], (char *)&pcb->prio);
 *	strcpy(info[4], (char *)&pcb->pcount);
 *	strcpy(info[5], (char *)&pcb->pstate);
 *	strcpy(info[6], (char *)&pcb->fd);
 *	strcpy(info[7], pcb->pname);
 *	strcpy(info[8], pcb->reg);
 *
 * }
*/
