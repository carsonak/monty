#include "linked_list.h"

/**
 * ln_new - allocates memory for a double link node and initialises it.
 * @n: the data to initialise with.
 *
 * Return: pointer to the node, NULL on failure.
 */
linked_node *ln_new(const int n)
{
	linked_node *new_node = malloc(sizeof(*new_node));

	if (!new_node)
		return (NULL);

	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->n = n;
	return (new_node);
}

/**
 * ln_unlink - removes a node from a list and returns pointer to the node.
 * @node: pointer to the node to remove.
 *
 * Return: pointer to the removed node, NULL on error.
 */
linked_node *ln_unlink(linked_node *const node)
{
	if (!node)
		return (NULL);

	if (node->next)
		node->next->prev = node->prev;

	if (node->prev)
		node->prev->next = node->next;

	node->next = NULL;
	node->prev = NULL;
	return (node);
}

/**
 * ln_delete - deletes a node and returns its data.
 * @node: the node to delete.
 *
 * Return: data in the node.
 */
int ln_delete(linked_node *const node)
{
	int n;

	if (!node)
		return (0);

	n = node->n;

	node->n = 0;
	free(ln_unlink(node));
	return (n);
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

	if (!head)
		return (NULL);

	while (walk->next)
	{
		walk = walk->next;
		ln_delete(walk->prev);
	}

	ln_delete(walk);
	return (NULL);
}
