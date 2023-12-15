#include "monty.h"

/**
 * mod - computes the modulus of the second top element
 * of the stack by top element of the stack
 * @stack: address of the head of the list
 * @line_number: current line number
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;
	int count = 0, temp;

	if (curr)
	{
		while (curr)
		{
			count++;
			curr = curr->next;
		}
		if (count < 2)
			clean_exit(*stack, "mod_blw2", NULL, line_number);
		if ((*stack)->n == 0)
			clean_exit(*stack, "mod_zero", NULL, line_number);
		temp = (*stack)->n;
		pop(stack, line_number);
		(*stack)->n = (*stack)->n % temp;
	}
	else
		clean_exit(*stack, "mod_blw2", NULL, line_number);
}
