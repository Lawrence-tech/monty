#include "monty.h"

/**
  *get_opcode_func - get the option of char input to perform the opcode
  *@head: pointer to the head of the stack
  *@l_num: line number of command.
  *input opcode
  *Return: a pointer to the func given the opcode. Null if none.
  */
void get_opcode_func(stack_t **head, unsigned int l_num)
{
	instruction_t stack[] = {
		{"push", stack_push},
		{"pall", stack_pall},
		{"pint", stack_pint},
		{"pop", stack_pop},
		{"add", stack_add},
		{"swap", stack_swap},
		{"nop", stack_nop},
		{NULL, NULL}
	};
	int i;

	for (i = 0; stack[i].opcode != NULL; i++)
		if (!strcmp(stack[i].opcode, s))
			return (stack[i].f);
	return (NULL);
}
