#ifndef STATUS_H
#define STATUS_H

/**
 * enum status_s - enum for process status
 *
 * @OK: sucess
 * @FAILED: failure
 * @ERR_M: memory allocation error
 *
 * Return: return nothing
*/

typedef enum status_s
{
	OK,
	FAILED,
	MALLOC_ERR,
	FDT_ERR,
	OFILE_ERR;
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

#endif	/* STATUS_H */
