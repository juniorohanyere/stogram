#ifndef PCB_H
#define PCB_H

#define PCB pcb_t
#define TCB tcb_t
#define PCB_SIZE (1024 * 10)

#include <stdint.h>

#include "fdt.h"
#include "indicator.h"

/**
 * struct pcb_s - Process Control Block structure
 *
 * @children: an array of integer for storing the PIDs of child process of a
 *	      parent process
 * @ppid: the parent process id
 * @prio: the priority
 * @pc: the program counter
 * @status: the exit status of the process
 * @state: the process state (idle, running, ready, bocked, terminated, etc)
 * @name: the process name
 * @reg: registers
 * @meminfo: the process memory information
 * @fdt: file descriptor table
 * @tcb: thread control block
 *
 * Return: return nothing
*/

typedef struct pcb_s
{
	int *children;
	uint16_t ppid, prio, pc;
	status_t status;
	state_t state;
	char *name, *reg;
	/* meminfo_t *meminfo; */
	FDT *fdt;
	/* TCB *tcb; */
} pcb_t;

void init_process(void);
uint16_t create_process(uint16_t ppid, uint16_t prio, char *name);

#endif	/* PCB_H */
