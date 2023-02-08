#include "monty.h"

/**
  *stack_add - adds omly the top two elements of stac.
  *@head: pointer to the head of stack.
  *@l_num: the number of line of command.
  */
void stack_add(stack_t **head, unsigned int l_num)
{
	stack_t *tmp = NULL;
	int nel = 0;

	tmp = *head;
	while (tmp)
	{
		nel++;
		tmp = tmp->next;
	}
	if (nel < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", l_num);
		free_vars();
		exit(EXIT_FAILURE);
	}
	tmp = (*head)->next;
	tmp->n += (*head)->n;
	stack_pop(head, l_num);
}
