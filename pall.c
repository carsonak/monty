#include "monty.h"

#include <assert.h>

/**
 * pall - prints all values on the deque.
 * @dq: pointer to the deque.
 * @line_number: current line number.
 */
void pall(deque * const dq, const unsigned int line_number)
{
	const linked_node *walk = NULL;

	(void)line_number;
	assert(dq);
	walk = dq->first;
	while (walk)
	{
		printf("%d\n", walk->n);
		walk = walk->next;
	}
}
