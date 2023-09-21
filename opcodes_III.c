#include "monty.h"

/**
 * 
*/
void pchar(stack_t **stack)
{
    if (stack != NULL)
	{
		stack_t *current = *stack;

		while (current)
		{
			putchar(current->n);
            putchar(10);
			current = current->next;
		}
	}
}