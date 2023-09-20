#include "monty.h"

/**
 * add - Adds the top two elements of the stack.
 * @stack: A pointer to a pointer to the stack.
 * @line_number: The line number in the script.
 */
void add(stack_t **stack, int line_number)
{
    if (!stack || !*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    int result = (*stack)->n + (*stack)->next->n;
    pop(stack, line_number);  // Remove the top element
    (*stack)->n = result;     // Store the result in the second top element
}
