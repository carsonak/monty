#include "monty.h"

#include <assert.h>

/**
 * rotr - move the last element of the deque to the first.
 * @dq: pointer to the deque.
 * @line_number: current line number.
 */
void rotr(deque * const dq, const unsigned int line_number)
{
	linked_node *new_bottom, *old_bottom;

	(void)line_number;
	assert(dq);
	if (dq->len < 2)
		return;

	new_bottom = dq->last->prev;
	old_bottom = ln_unlink(dq->last);
	dq->last = new_bottom;
	dq->first = ln_insert_before(dq->first, old_bottom);
}
