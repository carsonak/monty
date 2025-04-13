#include "monty.h"

#include <assert.h>

/**
 * monty_math - generic function for executing math operations on the first
 * two numbers in the deque.
 * @dq: pointer to the deque.
 * @opcode: original opcode being executed.
 * @math_op: the math operation to carry out.
 * @line_number: the current line number.
 */
static void
monty_math(deque * const dq, const char *const opcode, const char math_op,
	const unsigned int line_number)
{
	const linked_node *first, *second;
	int result = 0;

	assert(dq);
	if (dq->len < 2)
	{
		print_error(STACK_TOO_SHORT, opcode, line_number);
		return;
	}

	first = dq->first;
	second = first->next;

	if ((math_op == '/' || math_op == '%') && first->n == 0)
	{
		print_error(DIVISION_BY_ZERO, opcode, line_number);
		return;
	}

	if (math_op == '+')
		result = (second->n + first->n);
	else if (math_op == '-')
		result = (second->n - first->n);
	else if (math_op == '*')
		result = (second->n * first->n);
	else if (math_op == '/')
		result = (second->n / first->n);
	else if (math_op == '%')
		result = (second->n % first->n);

	dq_pop_first(dq);
	dq->first->n = result;
}

/**
 * add - add the first two elements of the deque.
 * @dq: pointer to the deque.
 * @line_number: current line number.
 */
void add(deque * const dq, const unsigned int line_number)
{
	assert(dq);
	monty_math(dq, "add", '+', line_number);
}

/**
 * sub - subtract the first two elements of the deque.
 * @dq: pointer to the deque.
 * @line_number: current line number.
 */
void sub(deque * const dq, const unsigned int line_number)
{
	assert(dq);
	monty_math(dq, "sub", '-', line_number);
}

/**
 * mul - multiply the first two elements of the deque.
 * @dq: pointer to the deque.
 * @line_number: current line number.
 */
void mul(deque * const dq, const unsigned int line_number)
{
	assert(dq);
	monty_math(dq, "mul", '*', line_number);
}

/**
 * divide - divide the second element by the first element of the deque.
 * @dq: pointer to the deque.
 * @line_number: current line number.
 */
void divide(deque * const dq, const unsigned int line_number)
{
	assert(dq);
	monty_math(dq, "div", '/', line_number);
}

/**
 * mod - get modulo of the second element by first element of the deque.
 * @dq: pointer to the deque.
 * @line_number: current line number.
 */
void mod(deque * const dq, const unsigned int line_number)
{
	assert(dq);
	monty_math(dq, "mod", '%', line_number);
}
