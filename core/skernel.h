#ifndef SKERNEL_H
#define SKERNEL_H

#include <stdint.h>

int skernel(void);
void init_system(void);
void system_daemon(uint16_t pid);

#endif	/* SKERNEL_H */
