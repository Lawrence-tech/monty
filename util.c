#include "monty"

/**
  *free_stack - frees the double linked list
  *@head: pointer to the head of the stack
  */
void free_stack(stack_t **head)
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

/**
  *free_vars - frees all variables in the struct global
  */
void free_vars(void)
{
	free_stack(vars.head);
	free(vars.buffer);
	fclose(vars.fd);
}
