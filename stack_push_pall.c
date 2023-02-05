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
	stack_t *new_node = NULL;
	int value = 0;

	if (!str || !isdigit(*str))
	{
		fprintf(stderr, "L%u: Usage: push integer\n", l_num);
		free_vars();
		exit(EXIT_FAILURE);
	}
	value = atoi(str);
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_vars();
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	if (*head)
	{
		new_node->next = *head;
		(*head)->prev = new_node;
	}
	else
	{
		new_node->next = NULL;
	}
	*head = new_node;
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

