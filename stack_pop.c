#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "monty.h"

/**
  *stack_pop - removes the top element of the stack.
  *@head:pointer to the head of the stack.
  *@l_num: line number of command.
  */
void stack_pop(stack_t **head, unsigned int l_num)
{
	stack_t *temp = *head;

	if (*head)
	{
		*head = (*head)->next;
		free(temp);
	}
	else
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", l_num);
		free_vars();
		exit(EXIT_FAILURE);
	}
}

