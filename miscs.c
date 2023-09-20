#include "monty.h"

/**
 * free_stack - frees the stack
 * @stack: our pure stack
*/
void free_stack(stack_t **stack)
{
	while (*stack)
	{
		stack_t *temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}
