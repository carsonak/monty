#include "monty.h"

char *elem = NULL;
/**
 * main - entry point
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	FILE *fptr = NULL;
	char *lnptr = NULL, **tokens = NULL;
	size_t chr_num, ln_num = 0;
	stack_t *head = NULL;
	void (*fncptr)(stack_t **, int) = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fptr = fopen(argv[1], "r");
	if (!fptr)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((getline(&lnptr, &chr_num, fptr)) != -1)
	{
		ln_num++;
		tokens = tokenise(lnptr);
		if (!tokens)
		{
			fprintf(stderr, "Error: malloc failed\n");
			fclose(fptr);
			exit(EXIT_FAILURE;)
		}
		fncptr = compare(tokens[0]);
		if (fncptr == NULL)
		{
			fprintf(stderr, "%d: unknown instruction %s\n", ln_num, token[0]);
			fclose(fptr);
			exit(EXIT_FAILURE);
		}
		else
			fncptr(&head, ln_num);
	}

	return (0);
}

/**
 *
 */
char **tokenise(char *line)
{
	size_t i = 0;
	char *tokens = NULL;

	tokens = strtok(line, " \t\n");
	if (tokens)
	{
		tokens = strdup(tokens);
		elem = strtok(NULL, " \t\n");
	}

	return (tokens);
}
