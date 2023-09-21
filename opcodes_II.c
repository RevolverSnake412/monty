#include "monty.h"

/**
 * add - adds the last two elements
 * @stack: our pure stack
 * @line: line count
*/
void add(stack_t **stack, int line)
{
	stack_t *current = *stack;
	int temp;

	if (!current->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short", line);
		exit(EXIT_FAILURE);
	}

	temp = current->n;
	current = current->next;
	current->n = temp + current->n;

	*stack = current;
}
