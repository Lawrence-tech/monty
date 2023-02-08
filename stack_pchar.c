#include "monty.h"

/**
  *stack_pchar - print the top ASCII character of linked list.
  *@head: pointer to the head of the stack.
  *@l_num: the number line of command.
  */
void stack_pchar(stack_t **head, unsigned int l_num)
{
	if (head == NULL || *head == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", l_num);
		free_vars();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n < 0 || (*head)->n >= 128)
	{
		fprintf(stderr, "L%u: can't pchar, value out of ranger\n", l_num);
		free_vars();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*head)->n);
}
