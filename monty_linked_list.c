#include "monty_linked_list.h"

/**
 * ln_new - allocates memory for a double link node and initialises it.
 * @n: the data to initialise with.
 *
 * Return: pointer to the node, NULL on failure.
 */
linked_node *ln_new(const int n)
{
	linked_node *new_node = calloc(1, sizeof(*new_node));

	if (!new_node)
		return (NULL);

	new_node->n = n;
	return (new_node);
}

/**
 * ln_insert_after - inserts a double link node after another.
 * @this_node: the node to insert after.
 * @other_node: the node to insert.
 *
 * Return: pointer to the newly inserted node.
 */
linked_node *
ln_insert_after(linked_node *const this_node, linked_node *const other_node)
{
	if (!this_node)
		return (other_node);

	if (!other_node)
		return (this_node);

	other_node->prev = this_node;
	other_node->next = this_node->next;
	if (this_node->next)
		this_node->next->prev = other_node;

	this_node->next = other_node;
	return (other_node);
}

/**
 * ln_insert_before - insert a double link node before another.
 * @this_node: the node to insert before.
 * @other_node: the node to insert.
 *
 * Return: pointer to the newly inserted node.
 */
linked_node *
ln_insert_before(linked_node *const this_node, linked_node *other_node)
{
	if (!this_node)
		return (other_node);

	if (!other_node)
		return (this_node);

	other_node->next = this_node;
	other_node->prev = this_node->prev;
	if (this_node->prev)
		this_node->prev->next = other_node;

	this_node->prev = other_node;
	return (other_node);
}

/**
 * ln_remove - deletes a node and returns its data.
 * @node: the node to delete.
 *
 * Return: pointer to the data of the node.
 */
int ln_remove(linked_node *const node)
{
	int n = NULL;

	if (!node)
		return (NULL);

	n = node->n;
	node->n = 0;
	if (node->next)
		node->next->prev = node->prev;

	if (node->prev)
		node->prev->next = node->next;

	node->next = NULL;
	node->prev = NULL;
	free(node);
	return (n);
}

/**
 * ln_swap_data - replace data in a node.
 * @node: pointer to the node to modify.
 * @n: the data to swap in.
 *
 * Return: the old data in node, if node is NULL 0 will be returned.
 */
int ln_swap_data(linked_node *const node, const int n)
{
	int old_data = 0;

	if (!node)
		return (old_data);

	old_data = node->n;
	node->n = n;
	return (old_data);
}

/**
 * ll_clear - delete a doubly linked list from memory.
 * @head: pointer to the head of the doubly linked list.
 *
 * Return: NULL always.
 */
void *ll_clear(linked_node *const head)
{
	linked_node *walk = head;
	void *data = NULL;

	if (!head)
		return (NULL);

	while (walk->next)
	{
		walk = ln_get_next(walk);
		data = ln_remove(walk->prev);
	}

	data = ln_remove(walk);
	return (NULL);
}
