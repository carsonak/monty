#include "monty.h"

/**
 * rotl - moves the bottom element of the stack to the top
 * @stack: address of the head of the stack
 * @line_number: current line number
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *walk = *stack;

	(void)line_number;
	while (walk && walk->next)
		walk = walk->next;

	if (*stack && (*stack)->next)
	{
		walk->prev->next = NULL;
		walk->prev = NULL;
		walk->next = *stack;
		(*stack)->prev = walk;
		*stack = walk;
	}
}
