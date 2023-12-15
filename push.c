#include "monty.h"

/**
 * push - adds a new node at the start of a doubly linked list
 * @stack: address of the stack of the list
 * @line_number: current line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	int i = 0;
	char *alt = NULL;

	if (!carry_var.arg)
		clean_exit(*stack, "push_no_int", NULL, line_number);

	if (carry_var.arg[0] == '-')
		alt = carry_var.arg + 1;
	else
		alt = carry_var.arg;

	for (i = 0; alt[i]; i++)
		if (!isdigit(alt[i]))
			clean_exit(*stack, "push_no_int", NULL, line_number);

	if (stack)
		temp = malloc(sizeof(stack_t));

	if (temp)
	{
		if (carry_var.arg[0] == '-')
			temp->n = -atoi(alt);
		else
			temp->n = atoi(alt);

		temp->next = *stack;
		temp->prev = NULL;
		if (*stack)
			(*stack)->prev = temp;

		*stack = temp;
	}
	else
		clean_exit(*stack, "malloc", NULL, line_number);
}
