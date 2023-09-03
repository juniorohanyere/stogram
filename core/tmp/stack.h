#ifndef STACK_H
#define STACK_H

/**
 * struct stacks - type definition for a stack structure
 *
 * @n: the line number of @line
 * @lineptr: pointer to the lines in a file
 * @next: pointer to the next node
 *
 * Description: this is a singly linked list for storing and accessing valid
 *		stogram instructions
 *
 * Return: return nothing
*/

typedef struct stacks
{
	int n;
	char *lineptr;
	struct stacks *next;
} stacks_t;	/* would have preferred stack_t, but termux :(. lolz */

stacks_t new_stack(int n, char *lineptr);
void fill_stack(stacks_t **stack, int n, char *line);
void free_stack(stacks_t *stack);

#endif	/* STACK_H */
