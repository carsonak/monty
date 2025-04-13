#include "monty.h"

#include <errno.h>  /* errno */
#include <string.h> /* strtok, strcmp */

context_container context = {NULL, 1, 1};

/**
 * read_opcode - breaks a line into an opcode and its argument.
 * @line: pointer to the line.
 *
 * Return: pointer to the opcode string.
 */
static char *read_opcode(char *line)
{
	char *opcode = strtok(line, " \t\n");

	context.arg = strtok(NULL, " \t\n");
	return (opcode);
}

/**
 * exec_opcode - executes valid opcodes, otherwise prints an error.
 * @dq: pointer to the deque.
 * @opcode: pointer to the the opcode.
 * @line_number: current line number.
 */
static void
exec_opcode(deque * const dq, const char *opcode, const size_t line_number)
{
	int i = 0;
	const instruction_t instruction[] = {
		{"push", push},   {"pint", pint},   {"pall", pall}, {"swap", swap},
		{"pop", pop},     {"nop", nop},     {"add", add},   {"div", divide},
		{"sub", sub},     {"rotl", rotl},   {"rotr", rotr}, {"mod", mod},
		{"mul", mul},     {"pchar", pchar}, {"pstr", pstr}, {"stack", stack},
		{"queue", queue}, {NULL, NULL},
	};

	while (instruction[i].opcode)
	{
		if (strcmp(opcode, instruction[i].opcode) == 0)
		{
			instruction[i].f(dq, line_number);
			return;
		}

		++i;
	}

	print_error(UNKNOWN_OPCODE, opcode, line_number);
}

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: array of pointers to the arguments
 *
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char *argv[])
{
	FILE *script = NULL;
	size_t line_num = 0, line_size = 0;
	deque stk = {0};
	char *opcode = NULL, *line = NULL;

	if (argc != 2)
	{
		print_error(INVALID_ARGS, NULL, line_num);
		return (EXIT_FAILURE);
	}

	script = fopen(argv[1], "r");
	if (!script)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	errno = 0;
	while (context.ok == 1 && getline(&line, &line_size, script) != -1)
	{
		++line_num;
		opcode = read_opcode(line);
		if (opcode && opcode[0] != '#')
			exec_opcode(&stk, opcode, line_num);

		free(line);
		line = NULL;
	}

	if (context.ok == 1 && errno == ENOMEM)
		print_error(MALLOC_FAIL, NULL, line_num);

	free(line);
	fclose(script);
	dq_clear(&stk);
	if (context.ok == 0)
		return (EXIT_FAILURE);

	return (EXIT_SUCCESS);
}
