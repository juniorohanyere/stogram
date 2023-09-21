#ifndef PCB_H
#define PCB_H

#include <stdint.h>

/**
 * struct pcb_s - Process Control Block structure
 *
 * @id: the PCB id
 * @pid: the process id
 * @ppid: the parent process id
 * @pname: the process name
 * @prio: the priority
 * @pcount: the process counter
 * @reg: the cpu registers
 * @pstate: the process state (running, ready, bocked, terminated, etc)
 * @fd: open files
 * @meminfo: the memory information
 *
 * Description: uint16_t holds up to 65,535 values
 *
 * Return: return nothing
*/

typedef struct pcb_s
{
	uint16_t id;
	uint16_t pid;
	uint16_t ppid;
	uint16_t prio;
	uint16_t pcount;
	int pstate;
	int fd;
	char *pname;
	char *reg;
	meminfo_t *meminfo;
} pcb_t;

pcb_t create_pcb(uint16_t id, uint16_t pid, uint16_t ppid, uint16_t prio,
	uint16_t pcount, int pstate, int fd, char *pname, char *reg,
	meminfo_t *meminfo);

#endif	/* PCB_H */
