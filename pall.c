#include "monty.h"

/**
 * pall - prints elements of a list
 * @stack: address of the head of the list
 * @line_number: current line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *walk = *stack;
	(void)line_number;

	if (*stack == NULL)
		return;

	while (walk)
	{
		printf("%d\n", walk->n);
		walk = walk->next;
	}
}
