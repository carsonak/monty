#include "deque.h"

/**
 * dq_push_first - add a node to the start of the deque.
 * @dq: pointer to the deque.
 * @data: data that will be stored in the node.
 *
 * Return: pointer to the newly added node, NULL if `dq` is NULL or on failure.
 */
linked_node *dq_push_first(deque * const dq, int data)
{
	linked_node *new_first = ln_new(data);

	if (!dq || !new_first)
		return (NULL);

	dq->first = ln_insert_before(dq->first, new_first);
	if (!dq->last)
		dq->last = dq->first;

	++(dq->len);
	return (new_first);
}

/**
 * dq_push_last - add a node to the end of the deque.
 * @dq: pointer to the deque.
 * @data: data that will be stored in the node.
 *
 * Return: pointer to the newly added node, NULL if `dq` is NULL or failure.
 */
linked_node *dq_push_last(deque * const dq, int data)
{
	linked_node *new_last = ln_new(data);

	if (!dq || !new_last)
		return (NULL);

	dq->last = ln_insert_after(dq->last, new_last);
	if (!dq->first)
		dq->first = dq->last;

	++(dq->len);
	return (new_last);
}

/**
 * dq_pop_first - remove the first node of a deque and return its data.
 * @dq: pointer to the deque.
 *
 * Return: data that was in the old first node, 0 if dq is NULL.
 */
int dq_pop_first(deque * const dq)
{
	linked_node *old_first;
	int n;

	if (!dq || !dq->first)
		return (0);

	old_first = dq->first;

	dq->first = old_first->next;
	if (!dq->first)
		dq->last = NULL;

	n = ln_delete(old_first);

	if (dq->len)
		--(dq->len);

	return (n);
}

/**
 * dq_pop_last - remove the last node of a deque and return its data.
 * @dq: pointer to the deque.
 *
 * Return: data that was in the old last node, 0 if dq is NULL.
 */
int dq_pop_last(deque * const dq)
{
	linked_node *old_last;
	int n;

	if (!dq || !dq->last)
		return (0);

	old_last = dq->last;

	dq->last = old_last->next;
	if (!dq->last)
		dq->first = NULL;

	n = ln_delete(old_last);

	if (dq->len)
		--(dq->len);

	return (n);
}
