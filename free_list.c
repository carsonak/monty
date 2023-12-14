#include "monty.h"

/**
 * free_list - free a doubly linked list
 * @head: head of the doubly linked list
 */
void free_list(stack_t *head)
{
	if (head)
	{
		while (head->next)
		{
			head = head->next;
			free(head->prev);
		}

		free(head);
	}
}
