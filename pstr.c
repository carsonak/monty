#include "monty.h"

#include <assert.h>

/**
 * pstr - print the initial ascii characters in the stack
 * followed by a new line.
 * @stack: pointer to the stack.
 * @line_number: current line number
 */
void pstr(deque *stack, unsigned int line_number)
{
	linked_node *walk;

	(void)line_number;
	assert(stack);
	walk = stack->first;

	while (walk)
	{
		if (!isascii(walk->n))
			break;

		putchar(walk->n);
		walk = walk->next;
	}

	putchar('\n');
}
