#include "monty.h"

#include <assert.h>

/**
 * rotl - move the top element of the stack to the bottom.
 * @stack: pointer to the stack.
 * @line_number: current line number.
 */
void rotl(deque *stack, unsigned int line_number)
{
	linked_node *new_top, *old_top;

	(void)line_number;
	assert(stack);
	if (stack->len < 2)
		return;

	new_top = stack->first->next;
	old_top = ln_unlink(stack->first);
	stack->first = new_top;
	stack->last = ln_insert_after(stack->last, old_top);
}
