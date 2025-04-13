#include "monty.h"

#include <assert.h>

/**
 * rotl - move the first element of the deque to the last.
 * @dq: pointer to the deque.
 * @line_number: current line number.
 */
void rotl(deque *dq, unsigned int line_number)
{
	linked_node *new_top, *old_top;

	(void)line_number;
	assert(dq);
	if (dq->len < 2)
		return;

	new_top = dq->first->next;
	old_top = ln_unlink(dq->first);
	dq->first = new_top;
	dq->last = ln_insert_after(dq->last, old_top);
}
