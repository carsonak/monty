#include "monty.h"

/**
 * print_error - print out error messages.
 * @err: error code.
 * @opcode: operation being carried out when error was encountered.
 * @ln_num: current line number.
 */
void print_error(enum error_code err, const char *const opcode, size_t ln_num)
{
	switch (err)
	{
	case DIVISION_BY_ZERO:
		fprintf(stderr, "L%ld: division by zero\n", ln_num);
		break;
	case EMPTY_STACK:
		fprintf(stderr, "L%ld: can't %s, stack empty\n", ln_num, opcode);
		break;
	case INVALID_ARGS:
		fprintf(stderr, "USAGE: monty file\n");
		break;
	case UNKNOWN_OPCODE:
		fprintf(stderr, "L<line_number>: unknown instruction %s\n", opcode);
		break;
	case MALLOC:
		fprintf(stderr, "Error: malloc failed\n");
		break;
	case PCHAR_OUT_OF_RANGE:
		fprintf(stderr, "L%ld: can't pchar, value out of range\n", ln_num);
		break;
	case PINT_EMPTY_STACK:
		fprintf(stderr, "L%ld: can't pint an empty stack\n", ln_num);
		break;
	case PUSH_NO_INTEGER:
		fprintf(stderr, "L%ld: usage: push integer\n", ln_num);
		break;
	case STACK_TOO_SHORT:
		fprintf(stderr, "L%ld: can't %s, stack too short\n", ln_num, opcode);
		break;
	default:
		break;
	}
}
