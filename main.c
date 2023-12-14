#include "monty.h"

char *elem = NULL;

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
	char *lnptr = NULL, *token = NULL;

	if (argc != 2)
		clean_exit(head, "usage", fptr, ln_num);

	fptr = fopen(argv[1], "r");
	if (!fptr)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	clean_exit(NULL, NULL, fptr, 0);
	while ((getline(&lnptr, &chr_num, fptr)) != -1)
	{
		ln_num++;
		token = tokenise(lnptr);
		if (token)
		{
			fncptr = compare(token);
			if (fncptr != NULL)
				fncptr(&head, ln_num);
			else
			{
				fprintf(stderr, "%ld: unknown instruction %s\n", ln_num, token);
				clean_exit(head, "None", fptr, ln_num);
				free(lnptr);
				exit(EXIT_FAILURE);
			}
		}
		free(lnptr);
		lnptr = NULL;
	}

	free(lnptr);
	fclose(fptr);
	free_list(head);
	return (EXIT_SUCCESS);
}
