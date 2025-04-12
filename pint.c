#include "monty.h"

#include <assert.h>

/**
 * pint - print the value at the top of stack.
 * @stack: pointer to the stack.
 * @line_number: current line number.
 */
void pint(deque *stack, unsigned int line_number)
{
	assert(stack);
	if (stack->len < 1)
	{
		print_error(EMPTY_STACK, "pint", line_number);
		return;
	}

	printf("%d\n", stack->first->n);
}
