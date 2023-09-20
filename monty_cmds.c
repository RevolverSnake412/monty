#include "monty.h"

void push(stack_t **stack, char *arg, int i)
{
    int value = atoi(arg);
    stack_t *new_node = malloc(sizeof(stack_t));

    if (atoi(arg) == 0 && strcmp(arg, "0") != 0)
    {
        fprintf(stderr, "L%d: usage: push integer\n", i);
        exit (EXIT_FAILURE);
    }

    if (!new_node)
    {
        perror("malloc");
        exit (EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack)
        (*stack)->prev = new_node;

    *stack = new_node;
}

void pall(stack_t **stack)
{
    if (stack != NULL)
    {
        stack_t *current = *stack;

        while (current)
        {
            printf("%d\n", current->n);
            current = current->next;
        }
    }
}