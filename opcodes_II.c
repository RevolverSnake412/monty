#include "monty.h"

/**
 * add - adds the last two elements
 * @stack: our pure stack
 * @line: line count
*/
void add(stack_t **stack, int line)
{
	stack_t *current;
	int temp;

	if (*stack == NULL || (**stack).next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
    current = *stack;
	temp = current->n;
	current = current->next;
	current->n = temp + current->n;

	*stack = current;
}
