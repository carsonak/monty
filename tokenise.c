#include "monty.h"

/**
 * tokenise - tokenises a line into two strings
 * @line: the line
 *
 * Return: pointer to the first token
 */
char *tokenise(char *line)
{
	char *token = NULL;

	if (line[0] == '#')
		token = "#";
	else
	{
		token = strtok(line, " \t\n");
		carry_var.arg = strtok(NULL, " \t\n");
	}

	return (token);
}
