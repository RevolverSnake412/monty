#include "monty.h"

/**
 * pop - Removes the top element of the stack.
 * @stack: A pointer to a pointer to the stack.
 * @line_number: The line number in the script.
 */
void pop(stack_t **stack, int line_number)
{
    if (!stack || !*stack)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    stack_t *temp = *stack;
    *stack = (*stack)->next;
    
    free(temp);

    if (*stack)
    {
        (*stack)->prev = NULL;
    }
}
