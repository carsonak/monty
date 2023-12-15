#include "monty.h"

/**
 * rotr - moves the top element of the stack to the bottom
 * @stack: address of the head of the stack
 * @line_number: current line number
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack, *walk = *stack;

	(void)line_number;
	while (walk && walk->next)
		walk = walk->next;

	if (*stack && (*stack)->next)
	{
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		walk->next = temp;
		temp->prev = walk;
		temp->next = NULL;
	}
}
