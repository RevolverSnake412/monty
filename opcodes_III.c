#include "monty.h"

/**
 * pchar - prints number as char in ASCII
 * @stack: our pure stack
 * @line: line count
*/
void pchar(stack_t **stack, int line)
{
	if (stack != NULL)
	{
		stack_t *current = *stack;

		if (current == NULL)
		{
			fprintf(stderr, "L%d: can't pchar, stack empty\n", line);
			free_stack(stack);
			exit(EXIT_FAILURE);
		}

		while (current)
		{
			if (current->n > 127 || current->n < 0)
			{
				fprintf(stderr, "L%d: can't pchar, value out of range\n", line);
				free_stack(stack);
				exit(EXIT_FAILURE);
			}
			putchar(current->n);
			putchar(10);
			current = current->next;
		}
	}
}
