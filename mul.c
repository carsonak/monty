#include "monty.h"

/**
 * mul - multiplies the first two elements of the stack
 * @stack: pointer to the head of the stack
 * @line_number: current line number
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int prod = 0, nodes = 0;
	stack_t *walk = *stack;

	while (walk)
	{
		walk = walk->next;
		nodes++;
	}

	if (nodes < 2)
		clean_exit(*stack, "mul_less", NULL, line_number);

	prod = (*stack)->n * (*stack)->next->n;
	pop(stack, line_number);
	(*stack)->n = prod;
}
