#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

/**
  *struct stack_s - doubly linked list representatin of a stack/queue
  *@n: integer
  *@prev: pointer to previous element of stack/queue
  *@next: pointer to next element
  *Description: doubly linked list node structure for stack, queue
  *LIFO, FIFO
  */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
  *struct instruction_s - opcode and its function
  *@opcode: the opcode
  *@f: function to handle the opcode
  *Description: opcode and its function for stack,queue. LIFO,FIFO
  */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
  *struct global_variables - global var to initialize
  *@order: mode
  *@fd: file description
  *@buffer: pointer data allocater for each line
  *@head: head of list(stack)
  *@stack: stack
  *@cline: line counter
  */
typedef struct global_variables
{
	int order;
	FILE *fd;
	unsigned int cline;
	char *buffer;
	stack_t *stack;
	stack_t *head;
} global_t;

extern global_t vars;
void get_opcode(stack_t **head, unsigned int l_num);
stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);
void free_vars(void);
void free_stack(stack_t *head);
void stack_push(stack_t **head, unsigned int l_num);
void stack_pall(stack_t **head, unsigned int l_num);
void stack_pint(stack_t **head, unsigned int l_num);
void stack_pop(stack_t **head, unsigned int l_num);
void stack_add(stack_t **head, unsigned int l_num);
void stack_swap(stack_t **head, unsigned int l_num);
void stack_nop(stack_t **head, unsigned int l_num);
void stack_sub(stack_t **head, unsigned int l_num);
void stack_div(stack_t **head, unsigned int l_num);
void stack_mul(stack_t **head, unsigned int l_num);
void stack_mod(stack_t **head, unsigned int l_num);
void stack_pchar(stack_t **head, unsigned int l_num);
void stack_pstr(stack_t **head, unsigned int l_num);
void stack_queue(stack_t **head, unsigned int l_num);
void order_stack(stack_t **head, unsigned int l_num);
FILE *check_open(int argc, char **argv);
void init(FILE *fd);

#endif /*MONTY_H*/
