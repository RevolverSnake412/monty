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

	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	temp = current->n + current->next->n;
	current->next->n = temp;
	*stack = current->next;
	free(current);
}

/**
 * sub - subs the last two elements
 * @stack: our pure stack
 * @line: line count
*/
void sub(stack_t **stack, int line)
{
	if (*stack == NULL || (**stack).next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	(**stack).next->n = (**stack).next->n - (**stack).n;
	*stack = (**stack).next;
}


/**
 * div - divs the last two elements
 * @stack: our pure stack
 * @line: line count
*/
void _div(stack_t **stack, int line)
{
	if (*stack == NULL || (**stack).next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	if ((**stack).n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	(**stack).next->n = (**stack).next->n / (**stack).n;
	*stack = (**stack).next;
}

/**
 * mul - muls the last two elements
 * @stack: our pure stack
 * @line: line count
*/
void mul(stack_t **stack, int line)
{
	if (*stack == NULL || (**stack).next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	(**stack).next->n = (**stack).next->n * (**stack).n;
	*stack = (**stack).next;
}

/**
 * mod - mods the last two elements
 * @stack: our pure stack
 * @line: line count
*/
void mod(stack_t **stack, int line)
{
	if (*stack == NULL || (**stack).next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	(**stack).next->n = (**stack).next->n % (**stack).n;
	*stack = (**stack).next;
}
