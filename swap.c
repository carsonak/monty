#include "monty.h"

#include <assert.h>

/**
 * swap - swaps the top two elements of the stack.
 * @stack: pointer to the stack.
 * @line_number: current line number.
 */
void swap(deque *stack, unsigned int line_number)
{
	linked_node *first, *second;
	int temp;

	assert(stack);
	if (stack->len < 2)
	{
		print_error(STACK_TOO_SHORT, "swap", line_number);
		return;
	}

	first = stack->first;
	second = first->next;
	temp = first->n;

	first->n = second->n;
	second->n = temp;
}
