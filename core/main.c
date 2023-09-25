#include <stdio.h>

#include "fdt.h"
#include "pcb.h"
#include "externs.h"

int main(void)
{
	int32_t p;

	init_fdt();
	init_process();

	if (pcb->_errno == MALLOC_ERR)
	{
		malloc_error();
		exit(EXIT_FAILURE);
	}

	/* first process, lolz */
	p = create_process(0, 0, 1, RUNNING, "systemd", "0x00");

	return (p);
}
