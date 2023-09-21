#include "monty.h"

/**
 * add - adds the last two elements
 * @stack: our pure stack
 * @line: line count
*/
void add(stack_t **stack, int line)
{
	int temp;

	if (*stack == NULL || (**stack).next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	temp = (**stack).n;
	*stack = (**stack).next;
	(**stack).n = temp + (**stack).n;
}
