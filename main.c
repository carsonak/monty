#include "monty.h"

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
			/*Malloc Fail*/
		}
	}

	return (0);
}

/**
 *
 */
char **tokenise(char *line)
{
	size_t i = 0;
	char **tokens = malloc(sizeof(char *) * 2);
	char *str = NULL;

	if (tokens)
	{
		str = strtok(line, " \t\n");
		for (i = 0; i < 2; i++)
		{
			if (str)
			{
				(*tokens)[i] = strdup(str);
				if (!(*tokens)[i])
					return (NULL);
			}
			else
				(*tokens)[i] = NULL;

			str = strtok(NULL, " \t\n");
		}
	}

	return (tokens);
}
