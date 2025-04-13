#include "monty.h"

#include <assert.h>

/**
 * pop - remove the first element of the deque.
 * @dq: pointer to the deque.
 * @line_number: current line number.
 */
void pop(deque * const dq, const unsigned int line_number)
{
	assert(dq);
	if (dq->len < 1)
	{
		print_error(POP_EMPTY_STACK, "pop", line_number);
		return;
	}

	dq_pop_first(dq);
}
