#include "monty.h"

/**
 * _div - divides the second top element of the stack
 * by the top element of the stack
 * @stack: address of the head of the list
 * @line_number: current line number
 */
void _div(stack_t **stack, unsigned int line_number)
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
			clean_exit(*stack, "div_blw2", NULL, line_number);
		if ((*stack)->n == 0)
			clean_exit(*stack, "div_zero", NULL, line_number);
		temp = (*stack)->n;
		pop(stack, line_number);
		(*stack)->n = (*stack)->n / temp;
	}
	else
		clean_exit(*stack, "div_blw2", NULL, line_number);
}
