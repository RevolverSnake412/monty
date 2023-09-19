#include "monty.h"

stack_t *stack = NULL;

int main(int argc, char *argv[])
{
    FILE *file = fopen(argv[1], "r");
    char line[32];
    int i = 0;

    if (argc != 2)
    {
        printf("USAGE: monty file\n");
        exit (EXIT_FAILURE);
    }

    if (file == NULL)
    {
        printf("Error: Can't open file %s\n", argv[1]);
        exit (EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), file))
    {
        char *opcode, *arg;
        opcode = strtok(line, " \n");
        arg = strtok(NULL, " \n");

        i++;
        
        if (opcode)
        {
            if (strcmp(opcode, "push") == 0 && arg)
            {
                int value = atoi(arg);

                if (atoi(arg) == 0)
                {
                    printf("L%d: usage: push integer\n", i);
                    exit (EXIT_FAILURE);
                }
                push(&stack, value);
            }
            else if (strcmp(opcode, "pall") == 0)
            {
                pall(&stack);
            }
        }
    }

    fclose(file);
    return (0);
}