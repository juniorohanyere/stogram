#ifndef INDICATOR_H
#define INDICATOR_H

/**
 * enum status_s - enum for process status
 *
 * @OK: sucess
 * @FAILED: failure
 * @MALLOC_ERR: memory allocation error
 * @OFILE_ERR: error opening file
 * @PCB_FULL: when number of processes is at its peak
 * @FDT_FULL: file descriptor table full or any related fd errors
 * @INV_FD: invalid file descriptor
 *
 * Return: return nothing
*/

typedef enum status_s
{
	OK,
	FAILED,
	MALLOC_ERR,
	OFILE_ERR,
	PCB_FULL,
	FDT_FULL,
	INV_FD
} status_t;

/**
 * enum state_s - enum for process state
 *
 * @RUNNING: running state, meaning the process is still active
 * @IDLE: idle state
 * @SLEEPING: sleeping state
 * @BLOCKED: blocked state
 * @READY: ready state, meaning ready or queued for execution
 * @TERMINATED: process terminated
 *
 * Return: return nothing
*/

typedef enum state_s
{
	RUNNING,
	IDLE,
	SLEEPING,
	BLOCKED,
	READY,
	TERMINATED
} state_t;

#endif	/* INDICATOR_H */
