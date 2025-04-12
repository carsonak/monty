#include "monty_linked_list.h"

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
