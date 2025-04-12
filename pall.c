#include "monty.h"

#include <assert.h>

/**
 * pall - prints all values on the stack.
 * @stack: address of the head of the list
 * @line_number: current line number
 */
void pall(deque *stack, unsigned int line_number)
{
	linked_node *walk = NULL;

	(void)line_number;
	assert(stack);
	walk = stack->first;
	while (walk)
	{
		printf("%d\n", walk->n);
		walk = walk->next;
	}
}
