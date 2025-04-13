#define _XOPEN_SOURCE
#include "monty.h"

#include <assert.h>
#include <ctype.h>

/**
 * pchar - print the char at the first node of the deque.
 * @dq: pointer to the deque.
 * @line_number: current line number.
 */
void pchar(deque * const dq, const unsigned int line_number)
{
	assert(dq);
	if (dq->len < 1)
	{
		print_error(EMPTY_STACK, "pchar", line_number);
		return;
	}

	if (!isascii(dq->first->n))
	{
		print_error(PCHAR_NOT_ASCII, "pchar", line_number);
		return;
	}

	printf("%c\n", dq->first->n);
}
