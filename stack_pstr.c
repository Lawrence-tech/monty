#include "monty.h"

/**
  *stack_pstr -  prints the string starting at the top of the stack
  *@head: head of stack
  *@l_num: reference line
  */
void stack_pstr(stack_t **head, unsigned int l_num)
{
	stack_t *tmp;
	(void)l_num;

	tmp = *head;
	while (tmp && tmp->n > 0 && tmp->n < 128)
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
}
