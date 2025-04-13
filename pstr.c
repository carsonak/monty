#define _XOPEN_SOURCE
#include "monty.h"

#include <assert.h>
#include <ctype.h>

/**
 * pstr - print the first ascii characters in the deque followed by a new line.
 * @dq: pointer to the deque.
 * @line_number: current line number.
 */
void pstr(deque * const dq, const unsigned int line_number)
{
	const linked_node *walk;

	(void)line_number;
	assert(dq);
	walk = dq->first;

	while (walk && walk->n != 0)
	{
		if (!isascii(walk->n))
			break;

		putchar(walk->n);
		walk = walk->next;
	}

	putchar('\n');
}
