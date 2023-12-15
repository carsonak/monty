#include "monty.h"

/**
 * sub - subtract adds the first two elements of the stack
 * @stack: pointer to the head of the stack
 * @line_number: current line number
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int diff = 0, nodes = 0;
	stack_t *walk = *stack;

	while (walk)
	{
		walk = walk->next;
		nodes++;
	}

	if (nodes < 2)
		clean_exit(*stack, "sub_less", NULL, line_number);

	diff = (*stack)->next->n - (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = diff;
}
