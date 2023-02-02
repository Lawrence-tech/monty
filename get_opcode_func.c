#include "monty.h"

/**
  *get_opcode_func - get the option of char input to perform the opcode
  *@head: pointer to the head of the stack
  *@l_num: line number of command.
  *@s: input opcode
  *Return: a pointer to the func given the opcode. Null if none.
  */
void (*get_opcode_func(char *s))(stack_t **head, unsigned int l_num)
{
	int i = 0;
	instruction_t stack[] = {
		{"push", stack_push},
		{"pall", stack_pall},
		{"pint", stack_pint},
		{"swap", stack_swap},
		{"nop", stack_nop},
		{NULL, NULL}
	};

	while (stack[i].opcode)
	{
		if (strcmp(stack[i].opcode, s) == 0)
			break;
		i += 1;
	}
	return (stack[i].f);
}
