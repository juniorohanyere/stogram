#ifndef PCB_H
#define PCB_H

#define PCB pcb_t
#define TCB tcb_t

#include <stdint.h>

#include "fdt.h"
#include "status.h"

/**
 * struct pcb_s - Process Control Block structure
 *
 * @pid: the process id
 * @ppid: the parent process id
 * @prio: the priority
 * @pc: the program counter
 * @_errno: flag for handling errors
 * @status: the exit status of the process
 * @state: the process state (idle, running, ready, bocked, terminated, etc)
 * @name: the process name
 * @reg: the process cpu registers
 * @meminfo: the memory information
 * @fdt: file descritor table
 * @tcb: the thread control block (TCB)
 *
 * Description: the maximum number of processes is uint16_t (65,535)
 *
 * Return: return nothing
*/

typedef struct pcb_s
{
	uint16_t pid, ppid, prio, pc;
	status_t _errno, status;
	state_t state;
	char *name, *reg;
	meminfo_t *meminfo;
	FDT *fdt;
	TCB *tcb;
} pcb_t;

void init_process(void);
int32_t create_process(uint16_t ppid, uint16_t prio, uint16_t pc,
	status_t status, state_t state, char *name, char *reg);

#endif	/* PCB_H */
