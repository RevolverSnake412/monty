#include "monty.h"

/**
 * add - adds the last two elements
 * @stack: our pure stack
 * @line: line count
*/
void add(stack_t **stack, int line)
{
	if (*stack == NULL || (**stack).next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	(**stack).next->n = (**stack).next->n + (**stack).n;
	*stack = (**stack).next;
}
