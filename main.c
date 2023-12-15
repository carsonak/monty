#include "monty.h"

global_v carry_var;

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: array of pointers to the arguments
 *
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char *argv[])
{
	FILE *fptr = NULL;
	size_t chr_num, ln_num = 0;
	stack_t *head = NULL;
	void (*fncptr)(stack_t **, unsigned int) = NULL;
	char *token = NULL;

	if (argc != 2)
		clean_exit(NULL, "usage", NULL, 0);

	fptr = fopen(argv[1], "r");
	if (!fptr)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	clean_exit(NULL, NULL, fptr, 0);
	while ((getline(&carry_var.ln_ptr, &chr_num, fptr)) != -1)
	{
		ln_num++;
		token = tokenise(carry_var.ln_ptr);
		if (token && token[0] != '#')
		{
			fncptr = compare(token);
			if (fncptr != NULL)
				fncptr(&head, ln_num);
			else
			{
				fprintf(stderr, "L%ld: unknown instruction %s\n", ln_num, token);
				clean_exit(head, "None", fptr, ln_num);
			}
		}
		free(carry_var.ln_ptr);
		carry_var.ln_ptr = NULL;
	}

	free(carry_var.ln_ptr);
	fclose(fptr);
	free_list(head);
	return (EXIT_SUCCESS);
}
