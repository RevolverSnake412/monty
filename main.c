#include "monty.h"

stack_t *stack = NULL;

int main(int argc, char *argv[])
{
    FILE *file = fopen(argv[1], "r");
    char line[32];

    if (argc != 2)
    {
        printf("USAGE: monty file\n");
        return (EXIT_FAILURE);
    }

    if (file == NULL)
    {
        printf("Error: Can't open file %s\n", argv[1]);
        return (EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), file))
    {
        char *opcode, *arg;
        opcode = strtok(line, " \n");
        arg = strtok(NULL, " \n");
        
        if (opcode)
        {
            if (strcmp(opcode, "push") == 0 && arg)
            {
                int value = atoi(arg);
                push(&stack, value);
            }
            else if (strcmp(opcode, "pall") == 0)
            {
                pall(&stack);
            }
        }
    }

    fclose(file);
    return (EXIT_SUCCESS);
}