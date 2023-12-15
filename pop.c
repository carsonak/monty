#include "monty.h"

/**
 * pop - deletes the head of the stack
 * @stack: pointer to the head of the stack
 * @line_number: current line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *copy = *stack;

	if (!copy)
		clean_exit(*stack, "pop_empty", NULL, line_number);

	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;

	free(copy);
}
