#ifndef CHILD_H
#define CHILD_H

#include <stdint.h>

void add_child(uint16_t ppid, uint16_t pid);
void delete_child(uint16_t ppid, uint16_t pid);

#endif	/* CHILD_H */
