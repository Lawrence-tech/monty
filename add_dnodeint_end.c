#include "monty.h"

/**
  *add_dnodeint_end - add node at end of list
  *@head: pointer to the head of first node
  *@n: number to add to list
  *Return: pointer to new node
  */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new, *tmp;

	if (head == NULL)
		return (NULL);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_vars();
		exit(EXIT_FAILURE);
	}
	new->n = n;
	if (!(*head))
	{
		new->next = *head;
		new->prev = NULL;
		*head = new;
		return (new);
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	new->next = NULL;
	new->prev = tmp;
	tmp->next = new;
	return (new);
}
