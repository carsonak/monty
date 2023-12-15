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

	token = strtok(line, " \n");
	carry_var.arg = strtok(NULL, " \n");

	return (token);
}
