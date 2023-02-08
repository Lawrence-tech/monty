#include "monty.h"

/**
  *free_stack - function to free list(double linked).
  *@head: pointer to the head of the stack
  */
void free_stack(stack_t *head)
{
	stack_t *next;

	if (head == NULL)
		return;
	while (head->next != NULL)
	{
		next = head->next;
		free(head);
		head = next;
	}
	free(head);
}
