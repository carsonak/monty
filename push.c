#include "monty.h"

#include <assert.h>
#include <limits.h>

/**
 * read_int - extract a an int from a string.
 * @nstr: pointer to the string.
 * @number: address to store the extracted int.
 *
 * Return: 1 on success, 0 on error.
 */
static unsigned short int read_int(const char *const nstr, int *const number)
{
	char *end = NULL;
	long int n = 0;

	assert(number);
	if (!nstr)
		return (0);

	n = strtol(nstr, &end, 10);
	if (nstr == end)
		return (0);

	if (n >= INT_MAX)
		*number = INT_MAX;
	else if (n <= INT_MIN)
		*number = INT_MIN;
	else
		*number = n;

	return (1);
}

/**
 * push - adds a new node at the front of the deque.
 * @dq: pointer to the deque.
 * @line_number: current line number.
 */
void push(deque * const dq, const unsigned int line_number)
{
	int n = 0;
	linked_node *added_node = NULL;

	assert(dq);
	if (read_int(context.arg, &n) == 0)
		print_error(PUSH_NO_INTEGER, "push", line_number);

	if (context.stack_mode > 0)
		added_node = dq_push_first(dq, n);
	else
		added_node = dq_push_last(dq, n);

	if (!added_node)
		print_error(MALLOC_FAIL, "push", line_number);
}
