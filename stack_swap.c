#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "monty.h"

/**
  *stack_swap - swaps the top two elements of the stack.
  *@head: pointer to the head of the stack.
  *@l_num: line number of command.
  */
void stack_swap(stack_t **head, unsigned int l_num)
{
	stack_t *tmp = NULL;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", l_num);
		free_vars();
		exit(EXIT_FAILURE);
	}

	tmp = *head;
	*head = (*head)->next;
	tmp->next = (*head)->next;
	tmp->prev = *head;
	(*head)->next = tmp;
	(*head)->prev = NULL;
}

