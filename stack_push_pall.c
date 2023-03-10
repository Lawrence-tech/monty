#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "monty.h"
/**
  *stack_push - pushes an element to the stack.
  *@head: pointer to the head of the stack.
  *@l_num: line number of the command
  */
void stack_push(stack_t **head, unsigned int l_num)
{
	int number;
	stack_t *temp = vars.stack;
	char str[100];

	if (!temp)
	{
		fprintf(stderr, "L%u: ", l_num);
		fprintf(stderr, "usage: push integer\n");
		free_vars();
		exit(EXIT_FAILURE);
	}

	sprintf(str, "%d", temp->n);
	if (!isdigit(*str) && *str != '-')
	{
		fprintf(stderr, "L%d: usage: push integer\n", l_num);
		free_vars();
		exit(EXIT_FAILURE);
	}

	number = atoi(str);
	if (vars.order == 1)
		add_dnodeint(head, number);
	else
	add_dnodeint_end(head, number);
}

/**
  *stack_pall - prints all the values on the stack, starting from the top.
  *@head: pointer to the head of the stack.
  *@l_num: line number of the command.
  */
void stack_pall(stack_t **head, unsigned int l_num)
{
	stack_t *current = *head;

	(void)l_num;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

