#include "child.h"
#include "pcb.h"

/**
 * add_child - adds a process id to a list of process ids of a particular
 *	       process known as parent process id
 *
 * @pcb: process control block
 * @ppid: the parent process id to add the child pid to
 * @pid: the child pid to add to the list of child pids for @ppid
 *
 * Description: this function assume that 0 stands for empty space. Therefore
 *		it is important to note that when printing the list of child
 *		pids to any stream, the 0's standing for empty spaces should be
 *		handled
 *
 * Return: return nothing
*/

void add_child(PCB *pcb, uint16_t ppid, uint16_t pid)
{
	uint16_t i;

	for (i = 0; i < PCB_SIZE; i++)
	{
		if (pcb[ppid].children[i] == 0)
			pcb[ppid].children[i] = pid;
	}
}

/**
 * delete_child - deletes the pid of a child process from the list of child
 *		  processes owned by a parent process
 *
 * @pcb: process control block
 * @ppid: the parent process id
 * @pid: the child process id to delete from @ppid
 *
 * Description: this function assumes that 0 stands for empty space, therby,
 *		setting the deleted child pid to 0. Therefore it is important
 *		to note that when printing the list of child pids to any
 *		stream, the 0's standing for empty spaces should be handled
 *
 * Return: return nothing
*/

void delete_child(PCB *pcb, uint16_t ppid, uint16_t pid)
{
	uint16_t i;

	for (i = 0; i < PCB_SIZE; i++)
	{
		if (pcb[ppid].children[i] == pid)
			pcb[ppid].children[i] = 0;
	}
}
