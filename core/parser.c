#include <stdio.h>
#include <stdlib.h>

#include "read_file.h"
#include "error.h"

/**
 * parse - parses intructions for the stogram programming language
 *
 * @stack: linked list
 *
 * Description: valid instructions are stored in @stack for later use
 *
 * Return: return nothing
*/

void parse(stack_t *stack, 
