#include "monty.h"

#include <errno.h>

/**
 * print_error - print out error messages.
 * @err: error code.
 * @opcode: operation being carried out when error was encountered.
 * @line_num: current line number.
 */
void print_error(
	const error_code err, const char *const opcode,
	const unsigned int line_num)
{
	switch (err)
	{
	case DIVISION_BY_ZERO:
		fprintf(stderr, "L%u: division by zero\n", line_num);
		break;
	case EMPTY_STACK:
		fprintf(stderr, "L%u: can't %s, stack empty\n", line_num, opcode);
		break;
	case INVALID_ARGS:
		fprintf(stderr, "USAGE: monty file\n");
		break;
	case UNKNOWN_OPCODE:
		fprintf(stderr, "L%u: unknown instruction %s\n", line_num, opcode);
		break;
	case MALLOC_FAIL:
		fprintf(stderr, "Error: malloc failed\n");
		break;
	case PCHAR_NOT_ASCII:
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_num);
		break;
	case POP_EMPTY_STACK:
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_num);
		break;
	case PUSH_NO_INTEGER:
		fprintf(stderr, "L%u: usage: push integer\n", line_num);
		break;
	case STACK_TOO_SHORT:
		fprintf(stderr, "L%u: can't %s, stack too short\n", line_num, opcode);
		break;
	default:
		break;
	}

	context.ok = 0;
	errno = 0;
}
