#ifndef LINKED_NODES_H
#define LINKED_NODES_H

#include <stdlib.h> /* *alloc */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

typedef struct stack_s linked_node;

linked_node *ln_new(int data);
linked_node *
ln_insert_after(linked_node *const this_node, linked_node *const other_node);
linked_node *
ln_insert_before(linked_node *const this_node, linked_node *other_node);
void *ln_remove(linked_node *node);
void *ln_swap_data(linked_node *const node, int data);
void *ll_clear(linked_node *const head);

#endif /* LINKED_NODES_H */
