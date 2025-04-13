#ifndef MONTY_DEQUE_H
#define MONTY_DEQUE_H

#include <inttypes.h> /* intmax_t */
#include <stddef.h>   /* size_t */
#include <stdlib.h>   /* *alloc */

#include "linked_list.h"

/**
 * struct deque - a deque data structure.
 * @len: the number of nodes in the deque.
 * @first: pointer to the first of the deque.
 * @last: pointer to the last of the deque.
 */
struct deque
{
	intmax_t len;
	linked_node *first;
	linked_node *last;
};

typedef struct deque deque;

deque *dq_new(void);
linked_node *dq_push_first(deque *const dq, int data);
linked_node *dq_push_last(deque *const dq, int data);
int dq_pop_first(deque *const dq);
int dq_pop_last(deque *const dq);
void dq_clear(deque *const dq);
void *dq_delete(deque *const nullable_ptr);

#endif /* MONTY_DEQUE_H */
