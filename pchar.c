#define _XOPEN_SOURCE
#include "monty.h"

#include <assert.h>
#include <ctype.h>

/**
 * pchar -  print the char at the top of the stack.
 * @stack: pointer to the stack.
 * @line_number: current line number.
 */
void pchar(deque *stack, unsigned int line_number)
{
	assert(stack);
	if (stack->len < 1)
	{
		print_error(EMPTY_STACK, "pchar", line_number);
		return;
	}

	if (!isascii(stack->first->n))
	{
		print_error(PCHAR_NOT_ASCII, "pchar", line_number);
		return;
	}

	printf("%c\n", stack->first->n);
}
