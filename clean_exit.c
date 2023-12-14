#include "monty.h"

/**
 * clean_exit - print out error messages, close open files, free the stack
 * @stack: head of the stack
 * @err: error to print
 * @f_ptr: file stream
 * @ln_num: current line number
 */
void clean_exit(stack_t *stack, const char *err, FILE *f_ptr, size_t ln_num)
{
	static FILE *fptr;
	static size_t line_number;

	if (f_ptr)
		fptr = f_ptr;

	if (ln_num)
		line_number = ln_num;

	if (err)
	{
		if (!strcmp("malloc", err))
			fprintf(stderr, "Error: malloc failed\n");
		else if (!strcmp("push_error", err))
			fprintf(stderr, "L%ld: usage: push integer\n", line_number);
		else if (!strcmp("usage", err))
			fprintf(stderr, "USAGE: monty file\n");

		if (fptr)
			fclose(fptr);

		free_list(stack);
		exit(EXIT_FAILURE);
	}
}
