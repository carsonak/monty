#include "monty.h"

/**
 * add - adds the first two elements of the stack
 * @stack: pointer to the head of the stack
 * @line_number: current line number
 */
void add(stack_t **stack, unsigned int line_number)
{
	int sum = 0, nodes = 0;
	stack_t *walk = *stack;

	while (walk)
	{
		walk = walk->next;
		nodes++;
	}

	if (nodes < 2)
		clean_exit(*stack, "add_less", NULL, line_number);

	sum = (*stack)->n + (*stack)->next->n;
	pop(stack, line_number);
	(*stack)->n = sum;
}
