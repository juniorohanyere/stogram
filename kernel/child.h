#ifndef CHILD_H
#define CHILD_H

#include <stdint.h>

#include "pcb.h"

void add_child(PCB *pcb, uint16_t ppid, uint16_t pid);
void delete_child(PCB *pcb, uint16_t ppid, uint16_t pid);

#endif	/* CHILD_H */
