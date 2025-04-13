#include "monty.h"

#include <assert.h>

/**
 * pint - print the first value of the deque.
 * @dq: pointer to the deque.
 * @line_number: current line number.
 */
void pint(deque * const dq, const unsigned int line_number)
{
	assert(dq);
	if (dq->len < 1)
	{
		print_error(EMPTY_STACK, "pint", line_number);
		return;
	}

	printf("%d\n", dq->first->n);
}
