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

/**
 * 
*/
int pstr(stack_t **stack)
{
    int flag = 0;

	if (stack != NULL)
	{
		stack_t *current = *stack;

		while (current)
		{
            if ((current->n > 127 || current->n < 0) ||
            current->n == 0)
            {
                if (flag == 1)
                    putchar(10);
			    return (0);
            }
            flag = 1;
            putchar(current->n);
            current = current->next;
		}
        putchar(10);
	}
    return (0);
}