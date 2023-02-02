#include "monty.h"

global_t vars;

/**
  *init - initialize all variables in struct and keep values
  *@fd: file descriptor
  */
void init(FILE *fd)
{
	vars.order = 1;
	vars.fd = fd;
	vars.cline = 1;
	vars.buffer = NULL;
	vars.stack = NULL;
	vars.head = NULL;
}

/**
  *check_open - check if args rep a file or not
  *@argc: count
  *@argv: vector
  *Return: fd of file opened. -1 if it doesn't exit.
  */
FILE *chack_open(int argc, char **argv)
{
	FILE *fd;

	if (argc == 1 || argc > 2)
	{
		dprintf(2, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		dprintf(2, "Error: can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

/**
  *main - evaluates input to execute functions
  *@argc: count
  *@argv: vector
  *Return: EXIT_SUCCESS or EXIT_FAILURE
  */
int main(int argc, char **argv)
{
	FILE *fd;
	size_t size = 128;
	ssize_t l_num = 0;
	char *args[2] = {NULL, NULL};
	void (*f)(stack_t **head, unsigned int line_number);

	fd = check_open(argc, argv);
	init(fd);
	l_num = getline(&vars.buffer, &size, fd);
	while (l_num != -1)
	{
		args[0] = strtok(vars.buffer, "\n\t");
		if (args[0][0] != '#' && args[0])
		{
			f = get_opcode_func(args[0]);
			if (!f)
			{
				dprintf(2, "L%u: ", vars.cline);
				dprintf(2, "unkown instruction %s\n",
						args[0]);
				free_vars();
				exit(EXIT_FAILURE);
			}
			vars.stack = strtok(NULL, "\n\t");
			f(&vars.head, vars.cline);
		}
		l_num = getline(&vars.buffer, &size, fd);
		vars.cline++;
	}

	free_vars();
	return (0);
}
