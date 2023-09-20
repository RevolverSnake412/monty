#include "monty.h"

void push(stack_t **stack, char *arg, int line)
{
    int value;
    stack_t *new_node = malloc(sizeof(stack_t));
    int j = 0;

    for (; arg[j]; j++)
    {
        if (arg[0] == 45)
            continue;
        if (arg[j] > 57 || arg[j] < 48)
        {
            fprintf(stderr, "L%d: usage: push integer\n", line);
            free(line);
            free_stack(*stack);
            exit (EXIT_FAILURE);
        }
    }
    
    value = atoi(arg);

    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
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
            fprintf(stdout ,"%d\n", current->n);
            current = current->next;
        }
    }
}