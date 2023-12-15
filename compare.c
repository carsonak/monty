#include "monty.h"

/**
 * compare - checks if a string is a valid OPCODE
 * @token: string to be checked
 *
 * Return: Pointer to a function, NULL on no matches
 */
void (*compare(char *token))(stack_t **, unsigned int)
{
	instruction_t instruction[] = {
		{"push", push}, {"pint", pint},
		{"pall", pall}, {"swap", swap},
		{"pop", pop}, {"nop", nop},
		{"add", add}, {"div", _div},
		{"sub", sub},
		{"mul", mul},
		{NULL, NULL}};
	int i = 0;

	while (instruction[i].opcode)
	{
		if (strcmp(token, instruction[i].opcode) == 0)
			return (instruction[i].f);

		i++;
	}

	return (NULL);
}
