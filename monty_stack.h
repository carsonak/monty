#ifndef STACK_H
#define STACK_H

#include <stddef.h> /* size_t */
#include <stdlib.h> /* *alloc */

#include "monty_linked_list.h"

/**
 * struct monty_stack - a stack data structure.
 * @len: the number of nodes in the stack.
 * @top: pointer to the top of the stack.
 */
struct monty_stack
{
	size_t len;
	linked_node *top;
};

typedef struct monty_stack monty_stack;

monty_stack *stk_new(void);
linked_node *stk_push(monty_stack *const s, int data);
int stk_pop(monty_stack *const s);
void *stk_delete(monty_stack *const nullable_ptr);

#endif /* STACK_H */
