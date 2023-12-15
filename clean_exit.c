#include "monty.h"

/**
 * clean_exit - print out error messages, close open files, free the stack
 * @head: head of the stack
 * @err: error to print
 * @file_ptr: open file stream
 * @ln_num: current line number
 */
void clean_exit(stack_t *head, const char *err, FILE *file_ptr, size_t ln_num)
{
	static FILE *fptr;

	if (file_ptr)
		fptr = file_ptr;

	if (err)
	{
		if (!strcmp("malloc", err))
			fprintf(stderr, "Error: malloc failed\n");
		else if (!strcmp("usage", err))
			fprintf(stderr, "USAGE: monty file\n");
		else if (!strcmp("push_no_int", err))
			fprintf(stderr, "L%ld: usage: push integer\n", ln_num);
		else if (!strcmp("pop_empty", err))
			fprintf(stderr, "L%ld: can't pop an empty stack\n", ln_num);
		else if (!strcmp("add_less", err))
			fprintf(stderr, "L%ld: can't add, stack too short\n", ln_num);
		else if (!strcmp("sub_less", err))
			fprintf(stderr, "L%ld: can't sub, stack too short\n", ln_num);
		else if (!strcmp("mul_less", err))
			fprintf(stderr, "L%ld: can't mul, stack too short\n", ln_num);
		else if (!strcmp("pint_empty", err))
			fprintf(stderr, "L%ld: can't pint, stack empty\n", ln_num);
		else if (!strcmp("swap_blw2", err))
			fprintf(stderr, "L%ld: can't swap, stack too short\n", ln_num);
		else if (!strcmp("div_blw2", err))
			fprintf(stderr, "L%ld: can't div, stack too short\n", ln_num);
		else if (!strcmp("div_zero", err))
			fprintf(stderr, "L%ld: division by zero\n", ln_num);

		if (fptr)
			fclose(fptr);

		if (carry_var.ln_ptr)
			free(carry_var.ln_ptr);

		free_list(head);
		exit(EXIT_FAILURE);
	}
}
