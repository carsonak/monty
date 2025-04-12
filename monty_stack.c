#include "monty_stack.h"

/**
 * stk_new - allocates space for an empty stack.
 *
 * Return: pointer to the new stack, NULL on failure.
 */
stack *stk_new(void) { return (calloc(1, sizeof(stack))); }

/**
 * stk_push - push an item onto a.
 * @s: the stack to operate on.
 * @data: data that will be stored in the node.
 *
 * Return: pointer to the newly added node, NULL if s is NULL or failure.
 */
linked_node *stk_push(stack *const s, void *const data)
{
	linked_node *new_top = dln_new(data);

	if (!s)
		return (NULL);

	if (!new_top)
		return (NULL);

	s->top = dln_insert_before(s->top, new_top);
	++(s->len);
	return (new_top);
}

/**
 * stk_pop - pop the top node on the stack and returns the data.
 * @s: the stack to operate on.
 *
 * Return: data that was in the old top node, 0 if s is NULL.
 */
int stk_pop(stack *const s)
{
	linked_node *old_top = NULL;

	if (!s || !s->top)
		return (0);

	old_top = s->top;
	s->top = dln_get_next(old_top);
	int n = dln_remove(old_top);

	if (s->len)
		--(s->len);

	return (n);
}

/**
 * clear_stack - delete a stack.
 * @s: the stack to operate on.
 */
static void clear_stack(stack *const s)
{
	if (!s || !s->top)
		return;

	s->top = sll_clear(s->top);
	s->len = 0;
}

/**
 * stk_delete - delete a stack.
 * @nullable_ptr: pointer to the stack to delete.
 *
 * Return: NULL always.
 */
void *stk_delete(stack *const nullable_ptr)
{
	clear_stack(nullable_ptr);
	free(nullable_ptr);
	return (NULL);
}
