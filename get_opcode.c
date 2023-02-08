#include "monty.h"

/**
  *get_opcode - get the option of char input to perform the opcode
  *@head: pointer to the head of the stack
  *@l_num: line number of command.
  *@opc: opcode passed.
  *Return: a pointer to the func given the opcode. Null if none.
  */
void (*get_opcode(char *opc))(stack_t **head, unsigned int l_num)
{
	int i = 0;
	instruction_t stack[] = {
		{"push", stack_push},
		{"pall", stack_pall},
		{"pint", stack_pint},
		{"pop", stack_pop},
		{"add", stack_add},
		{"swap", stack_swap},
		{"nop", stack_nop},
		{"sub", stack_sub},
		{"div", stack_div},
		{"mul", stack_mul},
		{"mod", stack_mod},
		{"queue", stack_queue},
		{"stack", order_stack},
		{"pchar", stack_pchar},
		{"pstr", stack_pstr},
		{NULL, NULL}
	};

	while (stack[i].opcode)
	{
		if (strcmp(stack[i].opcode, opc) == 0)
			break;
		i += 1;
	}
	return (stack[i].f);
}
