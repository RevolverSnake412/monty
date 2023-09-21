#include "monty.h"

/**
 * execute - execute
 * @stack: our pure stack
 * @file: our pure file
 * @opcode: provided opcode
 * @arg: argument
 * @counter: line count
*/
void execute(stack_t **stack, FILE *file, char *opcode, char *arg, int counter)
{
	if (opcode)
	{
		if (strcmp(opcode, "push") == 0)
			push(stack, arg, counter);
		else if (strcmp(opcode, "pall") == 0)
			pall(stack);
		else if (strcmp(opcode, "pint") == 0)
			pint(stack, counter);
		else if (strcmp(opcode, "pop") == 0)
			pop(stack, counter);
		else if (strcmp(opcode, "swap") == 0)
			swap(stack, counter);
		else if (strcmp(opcode, "nop") == 0)
			nop(stack, counter);
		else if (strcmp(opcode, "add") == 0 ||
				strcmp(opcode, "sub") == 0 ||
				strcmp(opcode, "div") == 0 ||
				strcmp(opcode, "mul") == 0 ||
				strcmp(opcode, "mod") == 0)
			maths(stack, counter, opcode);
		else if (strcmp(opcode, "pchar") == 0)
			pchar(stack);
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", counter, opcode);
			fclose(file);
			exit(EXIT_FAILURE);
		}
	}
}

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

/**
 * maths - bundle of operations
 * @stack: our pure stack
 * @counter: line count
 * @opcode: the operator
*/
void maths(stack_t **stack, int counter, char *opcode)
{
	if (strcmp(opcode, "add") == 0)
		add(stack, counter);
	if (strcmp(opcode, "sub") == 0)
		sub(stack, counter);
	if (strcmp(opcode, "div") == 0)
		_div(stack, counter);
	if (strcmp(opcode, "mul") == 0)
		mul(stack, counter);
	if (strcmp(opcode, "mod") == 0)
		mod(stack, counter);
}
