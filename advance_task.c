#include "monty.h"

/**
  *stack_sub -  subtracts the top element of the stack from the second top
  *element of the stack.
  *@head: pointer to the head of stack
  *@l_num: line number of command
  */
void stack_sub(stack_t **head, unsigned int l_num)
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
		fprintf(stderr, "L%u: cant sub, stack too short\n", l_num);
		free_vars();
		exit(EXIT_FAILURE);
	}
	tmp = (*head)->next;
	tmp->n -= (*head)->n;
	stack_pop(head, l_num);
}

/**
  *stack_queue - sets format of the data to a FIFO stack
  *@head: pointer to head of stack
  *@l_num: line number of command
  */
void stack_queue(stack_t **head, unsigned int l_num)
{
	(void)head;
	(void)l_num;

	vars.order = 0;
}

/**
  *stack_div - divides the second top element of stack from the top element
  *@head: pointer to the head of stack
  *@l_num: the number of line of command
  */
void stack_div(stack_t **head, unsigned int l_num)
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
		fprintf(stderr, "L%u: can't div, stack too short\n", l_num);
		free_vars();
		exit(EXIT_FAILURE);
	}
	tmp = (*head)->next;
	tmp->n = (int)(tmp->n) / (*head)->n;
	stack_pop(head, l_num);
}

/**
  *stack_mul - multiplies the two elements of stack
  *@head: pointer to the head of stack
  *@l_num: the number of line of command
  */
void stack_mul(stack_t **head, unsigned int l_num)
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
		fprintf(stderr, "L%u: can't mul, stack too short\n", l_num);
		free_vars();
		exit(EXIT_FAILURE);
	}
	tmp = (*head)->next;
	tmp->n *= (*head)->n;
	stack_pop(head, l_num);
}

/**
  *stack_mod - computes the rest of the division of the second top
  *element of the stack by the top element of the stack.
  *@head: pointer to the head of stack
  *@l_num: the number of line of command
  */
void stack_mod(stack_t **head, unsigned int l_num)
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
		fprintf(stderr, "L%u: can't mod, stack too short\n", l_num);
		free_vars();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", l_num);
		free_vars();
		exit(EXIT_FAILURE);
	}
	tmp = (*head)->next;
	tmp->n = (int)(tmp->n) % (*head)->n;
	stack_pop(head, l_num);
}
