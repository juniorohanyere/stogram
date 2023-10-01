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
 * @RUNNING: (R) running state, meaning the process is still active
 * @SLEEPING: (S) interruptible sleep state
 * @IDLE: (I) idle state
 * @WAITING: (D) uninterruptible sleep state
 * @STOPPED: (T) resumable stopped process
 * @TRACED: (t) indicates that process is paused for debuggig
 * @ZOMBIE: (Z) terminated process that has not yet been cleaned up by its
 *	    parent process
 * @DEAD: (X) completely terminated, not resumable
 *
 * Return: return nothing
*/

typedef enum state_s
{
	RUNNING,	/* R */
	SLEEPING,	/* S */
	IDLE,		/* I */
	WAITING,	/* D */
	STOPPED,	/* T */
	TRACED,		/* t */
	ZOMBIE,		/* Z */
	DEAD		/* X */
} state_t;

#endif	/* INDICATOR_H */
