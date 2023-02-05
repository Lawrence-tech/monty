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
/** void stack_push(stack_t **head, unsigned int l_num)
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
**/
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

/**
  *stack_pint -  prints the value at the top of the stack
  *@head : pointer to the head of the stack.
  *@l_num: line number of command
  */
void stack_pint(stack_t **head, unsigned int l_num)
{
	if (*head)
	{
		printf("%d\n", (*head)->n);
	}
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", l_num);
		free_vars();
		exit(EXIT_FAILURE);
	}
}

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

/**
  *stack_nop - does nothing
  *@head: pointer to the head of stack
  *@l_num: line number of command.
  */
void stack_nop(stack_t **head, unsigned int l_num)
{
	(void) head;
	(void) l_num;
}
