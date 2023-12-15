#include "monty.h"

/**
 * pstr - prints the string starting at the top of the stack
 * followed by a new line
 * @stack: address of the head of the list
 * @line_number: current line number
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;

	(void)line_number;

	while(curr)
	{
		if (curr->n <= 0 || curr->n > 127)
			break;
		putchar(curr->n);
		curr = curr->next;
	}
	putchar('\n');
}
