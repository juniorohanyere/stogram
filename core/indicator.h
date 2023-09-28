#ifndef INDICATOR_H
#define INDICATOR_H

/**
 * enum status_s - enum for process status
 *
 * @OK: sucess
 * @FAILED: failure
 * @MALLOC_ERR: memory allocation error
 * @FDT_ERR: file descriptor table full or any related fd errors
 * @OFILE_ERR: error opening file
 * @IFD_ERR: invalid file descriptor
 *
 * Return: return nothing
*/

typedef enum status_s
{
	OK,
	FAILED,
	MALLOC_ERR,
	PCB_ERR,
	FDT_FULL,
	OFILE_ERR,
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
