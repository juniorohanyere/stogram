#ifndef FDT_H
#define FDT_H

#include "pcb.h"

FDT *init_fdt(PCB *pcb);
uint16_t open_file(PCB *pcb, uint16_t pid, const char *filename, int modes);
void clear_file(PCB *pcb, uint16_t pid, uint16_t fd);
void destroy_fdt(PCB *pcb, uint16_t pid);

#endif	/* FDT_H */
