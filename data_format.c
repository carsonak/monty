#include "monty.h"

/**
 * stack - set the format of the program data to a stack.
 * @dq: pointer to the deque.
 * @line_number: current line number.
 */
void stack(deque *dq, unsigned int line_number)
{
	(void)dq;
	(void)line_number;
	context.stack_mode = 1;
}

/**
 * queue - set the format of the program data to a queue.
 * @dq: pointer to the deque.
 * @line_number: current line number.
 */
void queue(deque *dq, unsigned int line_number)
{
	(void)dq;
	(void)line_number;
	context.stack_mode = 0;
}
