#include "monty.h"

/**
 * main - main
 * @argc: argv's index
 * @argv: arg array
 *
 * Return: 0 on success
*/
int main(int argc, char *argv[])
{
	FILE *file = fopen(argv[1], "r");
	stack_t *stack = NULL;
	char line[2048];
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), file))
	{
		char *opcode = strtok(line, " \t\n$");
		char *arg = strtok(NULL, " \t\n$");

		counter++;
		if (opcode)
		{
			if (strcmp(opcode, "push") == 0 && arg)
				push(&stack, arg, counter);
			else if (strcmp(opcode, "pall") == 0)
				pall(&stack);
			else if (strcmp(opcode, "nop") == 0)
				nop(&stack, counter);
			else
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", counter, opcode);
				fclose(file);
				exit(EXIT_FAILURE);
			}
		}
	}
	fclose(file);
	free_stack(&stack);
	return (0);
}
