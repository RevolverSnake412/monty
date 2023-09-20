#include "monty.h"

stack_t *stack = NULL;

int main(int argc, char *argv[])
{
    FILE *file = fopen(argv[1], "r");
    char line[32];
    int i = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit (EXIT_FAILURE);
    }

    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit (EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), file))
    {
        char *opcode = strtok(line, " \t\n$");
        char *arg = strtok(NULL, " \t\n$");
        i++;
        
        if (opcode)
        {
            if (strcmp(opcode, "push") == 0 && arg)
                push(&stack, arg, i);

            else if (strcmp(opcode, "pall") == 0)
                pall(&stack);
            else
            {
                fprintf(stderr, "L%d: unknown instruction %s\n", i, opcode);
                fclose(file);
                exit (EXIT_FAILURE);
            }
        }
    }

    fclose(file);
    return (0);
}