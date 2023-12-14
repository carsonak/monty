#include "monty.h"

/**
 */
void (*compare(char *token))(stack **, int) 
{
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall}
		{NULL, NULL}
	};
	int i = 0;

	while (instruction[i].opcode)
	{
		if (strcmp(token, instruction[i].opcode) == 0)
			return instruction[i].f;
		i++;
	}
	return (NULL);
}
