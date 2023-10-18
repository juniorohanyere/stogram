#ifndef SKERNEL_H
#define SKERNEL_H

#include <stdint.h>

#include "pcb.h"

int skernel(void);
void init_system(PCB *pcb);
void system_daemon(PCB *pcb, uint16_t pid);

#endif	/* SKERNEL_H */
