#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: address of the head of the list
 * @line_number: current line number
 */
void swap(stack_t **stack, unsigned int line_number)
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
			clean_exit(*stack, "swap_blw2", NULL, line_number);
		temp = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = temp;
	}
	else
		clean_exit(*stack, "swap_blw2", NULL, line_number);
}
