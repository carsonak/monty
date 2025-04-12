#include "monty.h"

#include <assert.h>

/**
 * monty_math - generic function for executing math operations on the first
 * two numbers in the stack.
 * @stack: pointer to the stack.
 * @opcode: original opcode being executed.
 * @math_op: the math operation to carry out.
 * @line_number: the current line number.
 */
static void
monty_math(deque *stack, const char *const opcode, const char math_op,
	unsigned int line_number)
{
	linked_node *first, *second;
	int result = 0;

	assert(stack);
	if (stack->len < 2)
	{
		print_error(STACK_TOO_SHORT, opcode, line_number);
		return;
	}

	first = stack->first;
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

	dq_pop_first(stack);
	stack->first->n = result;
}

/**
 * add - add the first two elements of the stack.
 * @stack: pointer to the stack.
 * @line_number: current line number.
 */
void add(deque *stack, unsigned int line_number)
{
	assert(stack);
	monty_math(stack, "add", '+', line_number);
}

/**
 * sub - subtract the first two elements of the stack.
 * @stack: pointer to the stack.
 * @line_number: current line number.
 */
void sub(deque *stack, unsigned int line_number)
{
	assert(stack);
	monty_math(stack, "sub", '-', line_number);
}

/**
 * mul - multiplies the first two elements of the stack
 * @stack: pointer to the head of the stack
 * @line_number: current line number
 */
void mul(deque *stack, unsigned int line_number)
{
	assert(stack);
	monty_math(stack, "mul", '*', line_number);
}

/**
 * divide - divides the second element by the first element of the stack.
 * @stack: pointer to the stack.
 * @line_number: current line number.
 */
void divide(deque *stack, unsigned int line_number)
{
	assert(stack);
	monty_math(stack, "div", '/', line_number);
}

/**
 * mod - get modulo of the second element by first element of the stack.
 * @stack: pointer to the stack.
 * @line_number: current line number.
 */
void mod(deque *stack, unsigned int line_number)
{
	assert(stack);
	monty_math(stack, "mod", '%', line_number);
}
