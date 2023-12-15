#include "monty.h"

/**
 * pint - prints the value at the top of stack
 * @stack: pointer to the head of the stack
 * @line_number: current line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack)
		printf("%d\n", (*stack)->n);
	else
		clean_exit(*stack, "pint_empty", NULL, line_number);
}
