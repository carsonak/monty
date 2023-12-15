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
	char *seg = NULL;

	if (file_ptr)
		fptr = file_ptr;

	if (err)
	{
		seg = strtok(strdup(err), "_");
		if (!strcmp("malloc", err))
			fprintf(stderr, "Error: malloc failed\n");
		else if (!strcmp("usage", err))
			fprintf(stderr, "USAGE: monty file\n");
		else if (!strcmp("push_no_int", err))
			fprintf(stderr, "L%ld: usage: push integer\n", ln_num);
		else if (!strcmp("pop_empty", err))
			fprintf(stderr, "L%ld: can't %s an empty stack\n", ln_num, seg);
		else if (!strcmp("add_less", err) || !strcmp("sub_less", err) ||
				 !strcmp("swap_blw2", err) || !strcmp("mul_less", err) ||
				 !strcmp("div_blw2", err) || !strcmp("mod_blw2", err))
			fprintf(stderr, "L%ld: can't %s, stack too short\n", ln_num, seg);
		else if (!strcmp("mod_zero", err) || !strcmp("div_zero", err))
			fprintf(stderr, "L%ld: division by zero\n", ln_num);
		else if (!strcmp("not_ascii", err))
			fprintf(stderr, "L%ld: can't pchar, value out of range\n", ln_num);
		else if (!strcmp("pchar_empty", err) || !strcmp("pint_empty", err))
			fprintf(stderr, "L%ld: can't %s, stack empty\n", ln_num, seg);

		if (fptr)
			fclose(fptr);

		if (carry_var.ln_ptr)
			free(carry_var.ln_ptr);

		free_list(head);
		free(seg);
		exit(EXIT_FAILURE);
	}
}
