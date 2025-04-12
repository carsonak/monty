#ifndef STACK_H
#define STACK_H

#include <stddef.h> /* size_t */
#include <stdlib.h> /* *alloc */

#include "monty_linked_list.h"

/**
 * struct stack - a stack data structure.
 * @len: the number of nodes in the stack.
 * @top: pointer to the top of the stack.
 */
struct stack
{
	size_t len;
	linked_node *top;
};

typedef struct stack stack;

stack *stk_new(void);
linked_node *stk_push(stack *const s, void *const data);
int stk_pop(stack *const s);
void *stk_delete(stack *const nullable_ptr);

#endif /* STACK_H */
