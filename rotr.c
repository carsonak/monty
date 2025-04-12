#include "monty.h"

#include <assert.h>

/**
 * rotr - move the bottom element of the stack to the top.
 * @stack: pointer to the stack.
 * @line_number: current line number.
 */
void rotr(deque *stack, unsigned int line_number)
{
	linked_node *new_bottom, *old_bottom;

	(void)line_number;
	assert(stack);
	if (stack->len < 2)
		return;

	new_bottom = stack->last->prev;
	old_bottom = ln_unlink(stack->last);
	stack->last = new_bottom;
	stack->first = ln_insert_before(stack->first, old_bottom);
}
