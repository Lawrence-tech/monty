#include <unistd.h>
#include <stdio.h>
#include "monty.h"
/**
  *stack_push - pushes an element to the stack.
  *@head: list head
  *@l_num: ref line with error
  */
void stack_push(stack_t **head, unsigned int l_num)
{
	int number = 0;
	int i = 0;

	if (!vars.stack)
	{
		dprintf(2, "L%u: Usage: push integer\n", l_num);
		free_vars();
		exit(EXIT_FAILURE);
	}

	while (vars.stack[i] != '\0')
	{
		if (!isdigit(vars.stack[i]) && vars.stack[i] != '-')
		{
			dprintf(2, "L%u: Usage: push integer\n", l_num);
			free_vars();
			exit(EXIT_FAILURE);
		}
		i++;
	}
	number = atoi(vars.stack);
	if (vars.order == 1)
		add_dnodeint(head, number);
	else
		add_dnodeint_end(head, number);
}

/**
  *stack_pall - prints all the values on the stack.
  *@head: list head.
  *@l_num: reading line
  */
void stack_pall(stack_t **head, unsigned int l_num)
{
	stack_t *tmp;
	(void)l_num;

	tmp = *head;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
  *stack_pint -  prints the value at the top of the stack
  *@head :list head
  *@l_num: ref line
  */
void stack_pint(stack_t **head, unsigned int l_num)
{
	if (*head == NULL)
	{
		dprintf(2, "L%u: can't pint, stack empty\n", l_num);
		free_vars();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
  *stack_pop - removes the top element of the stack.
  *@head:list head
  *@l_num: reading line
  */
void stack_pop(stack_t **head, unsigned int l_num)
{
	stack_t *tmp;

	if (*head == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", l_num);
		free_vars();
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	*head = (*head)->next;
	free(tmp);
}

/**
  *stack_swap - swaps the top two elements of the stack.
  *@head: list head
  *@l_num: reading line
  */
void stack_swap(stack_t **head, unsigned int l_num)
{
	stack_t *tmp = NULL;

	if (*head == NULL || (*head)->next == NULL)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", l_num);
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

