#include "monty.h"

#include <assert.h>

/**
 * pop - delete the head of the stack.
 * @stack: pointer to the stack.
 * @line_number: current line number.
 */
void pop(deque *stack, unsigned int line_number)
{
	assert(stack);
	if (stack->len < 1)
	{
		print_error(EMPTY_STACK, "pop", line_number);
		return;
	}

	dq_pop_first(stack);
}
