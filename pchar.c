#include "monty.h"

/**
 * pchar -  prints the char at the top of the stack
 * @stack: address of the head of the list
 * @line_number: current line number
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack && stack)
	{
		if ((*stack)->n < 0 || (*stack)->n > 127)
			clean_exit(*stack, "not_ascii", NULL, line_number);
		putchar((*stack)->n);
		putchar('\n');
	}
	else
		clean_exit(*stack, "empty_stack", NULL, line_number);
}
