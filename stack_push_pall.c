#include "monty.h"
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <limits.h>

/**
  *stack_push - pushes an element to the stack.
  *@head: pointer to the head of the stack.
  *@l_num: line number of the command
  */
void stack_push(stack_t **head, unsigned int l_num)
{
    long int value;
    char *endptr;
    stack_t *temp = *head;

    if (!temp)
    {
        fprintf(stderr, "L%u: ", l_num);
        fprintf(stderr, "usage: push integer\n");
        free_vars();
        exit(EXIT_FAILURE);
    }

    value = strtol((char *)&(temp->n), &endptr, 10);
    if (*endptr != '\0' || errno == ERANGE || value < INT_MIN || value > INT_MAX)
    {
        fprintf(stderr, "L%u: usage: push integer\n", l_num);
        free_vars();
        exit(EXIT_FAILURE);
    }

    if (vars.order == 1)
        add_dnodeint(head, (int)value);
    else
        add_dnodeint_end(head, (int)value);
}

/**
  *stack_pall - prints all the values on the stack, starting from the top.
  *@head: pointer to the head of the stack.
  *@l_num: line number of the command.
  */
void stack_pall(stack_t **head, unsigned int l_num)
{
    stack_t *current = *head;

    (void)l_num;
    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

