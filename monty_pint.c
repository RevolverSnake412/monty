#include "monty.h"

/**
 * pint - Prints the value at the top of the stack.
 * @stack: A pointer to a pointer to the stack.
 * @line_number: The line number in the script.
 */
void pint(stack_t **stack, int line_number)
{
    if (!stack || !*stack)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
    
    printf("%d\n", (*stack)->n);
}
