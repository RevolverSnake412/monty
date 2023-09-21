#include "monty.h"

/**
 * 
*/
void pchar(stack_t **stack, int line)
{
    if (stack != NULL)
	{
		stack_t *current = *stack;

		while (current)
		{
            if (current->n > 127 || current->n < 0)
            {
                fprintf(stderr, "L%d: can't pchar, value out of range\n", line);
                exit(EXIT_FAILURE);
            }
			putchar(current->n);
            putchar(10);
			current = current->next;
		}
	}
    else
    {
        fprintf(stderr, "L%d: can't pchar, stack empty\n", line);
        exit(EXIT_FAILURE);
    }
}