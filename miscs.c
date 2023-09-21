#include "monty.h"

/**
 * execute - execute
 * @opcode: provided opcode
 * @arg: argument
*/
void execute(stack_t **stack, FILE *file, char *opcode, char* arg, int counter)
{
    if (opcode)
		{
			if (strcmp(opcode, "push") == 0)
				push(stack, arg, counter);
			else if (strcmp(opcode, "pall") == 0)
				pall(stack);
			else if (strcmp(opcode, "swap") == 0)
				swap(stack, counter);
			else if (strcmp(opcode, "nop") == 0)
				nop(stack, counter);
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
