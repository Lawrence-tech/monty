#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "monty.h"

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

