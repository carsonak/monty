#include "monty_deque.h"

/**
 * dq_new - allocate space for an empty deque.
 *
 * Return: pointer to the new deque, NULL on failure.
 */
deque *dq_new(void)
{
	deque *new_deque = malloc(sizeof(*new_deque));

	new_deque->len = 0;
	new_deque->first = NULL;
	new_deque->last = NULL;
	return (new_deque);
}

/**
 * dq_clear - delete all elements of a deque.
 * @dq: pointer to the deque to clear.
 */
void dq_clear(deque *const dq)
{
	if (!dq || !dq->first)
		return;

	dq->first = ll_clear(dq->first);
	dq->last = NULL;
	dq->len = 0;
}

/**
 * dq_delete - delete a deque.
 * @nullable_ptr: pointer to the deque to delete.
 *
 * Return: NULL always.
 */
void *dq_delete(deque *const nullable_ptr)
{
	dq_clear(nullable_ptr);
	free(nullable_ptr);
	return (NULL);
}
