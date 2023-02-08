#include "monty.h"

/**
  *free_vars - frees all variables into the struct global_t.
  */
void free_vars(void)
{
	free_stack(vars.head);
	free(vars.buffer);
	fclose(vars.fd);
}
