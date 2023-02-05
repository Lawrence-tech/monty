#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "monty.h"

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
