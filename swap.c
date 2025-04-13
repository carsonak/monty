#include "monty.h"

#include <assert.h>

/**
 * swap - swaps the first two elements of the deque.
 * @dq: pointer to the deque.
 * @line_number: current line number.
 */
void swap(deque * const dq, const unsigned int line_number)
{
	linked_node *first, *second;
	int temp;

	assert(dq);
	if (dq->len < 2)
	{
		print_error(STACK_TOO_SHORT, "swap", line_number);
		return;
	}

	first = dq->first;
	second = first->next;
	temp = first->n;

	first->n = second->n;
	second->n = temp;
}
