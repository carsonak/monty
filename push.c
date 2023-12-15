#include "monty.h"

/**
 * push - adds a new node at the start of a doubly linked list
 * @stack: address of the stack of the list
 * @line_number: current line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (!carry_var.arg || !isdigit(carry_var.arg[0]))
		clean_exit(*stack, "push_no_int", NULL, line_number);

	if (stack)
		temp = malloc(sizeof(stack_t));

	if (temp)
	{
		temp->n = atoi(carry_var.arg);
		temp->next = *stack;
		temp->prev = NULL;
		if (*stack)
			(*stack)->prev = temp;

		*stack = temp;
	}
	else
		clean_exit(*stack, "malloc", NULL, line_number);
}
