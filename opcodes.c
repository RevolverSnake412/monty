#include "monty.h"

/**
 * push - adds a new element into the slack
 * @stack: our pure stack
 * @arg: the value to be added
 * @line: line count for errors
*/
void push(stack_t **stack, char *arg, int line)
{
	int value;
	stack_t *new_node = malloc(sizeof(stack_t));
	int j = 0;

	if (arg == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line);
		exit(EXIT_FAILURE);
	}

	for (; arg[j]; j++)
	{
		if (arg[0] == 45)
			continue;
		if ((arg[j] > 57 || arg[j] < 48) || arg == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line);
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
	}

	value = atoi(arg);

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * pall - display the content of the stack
 * @stack: our pure stack
*/
void pall(stack_t **stack)
{
	if (stack != NULL)
	{
		stack_t *current = *stack;

		while (current)
		{
			fprintf(stdout, "%d\n", current->n);
			current = current->next;
		}
	}
}

/**
 * pint - prints last element of the stack
 * @stack: our pure stack
 * @line: line count
*/
void pint(stack_t **stack, int line)
{
	stack_t *current = *stack;

	if (current == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}

	fprintf(stdout, "%d\n", current->n);
}

void pop(stack_t **stack, int line)
{

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		free_stack(&stack);
		exit(EXIT_FAILURE);
	}

	*stack = (**stack).next;
}

/**
 * swap - swaps last 2 elements in stack
 * @stack: our pure stack
 * @line: line count
*/
void swap(stack_t **stack, int line)
{
	stack_t *current = *stack;
	int temp;

	if (!current || current->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		free_stack(&current);
		exit(EXIT_FAILURE);
	}

	temp = current->n;
	current->n = current->next->n;
	current->next->n = temp;
}
