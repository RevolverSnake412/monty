#include "monty.h"

void free_stack(stack_t *stack)
{
    stack_t *temp = stack;
   
    while (stack)
    {
        temp = stack->next;
        free(temp);
        stack = temp;
    }
}