#ifndef MONTY_H
#define MONTY_H

/*** LIBRARIES ***/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/*** STRUCTS ***/
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*** GLOBAL VARIABLES ***/
extern stack_t *stack;
extern FILE *file;

/**************** FUNCTIONS ****************/
/*** MISCS_C ***/
void execute(stack_t **stack, FILE *file,
			char *opcode, char *arg,
			int counter);
void free_stack(stack_t **stack);

/*** MONTY_CMDS_C ***/
void push(stack_t **stack, char *arg, int i);
void pall(stack_t **stack);
void pint(stack_t **stack, int line);
void pop(stack_t **stack, int line);
void swap(stack_t **stack, int line);
void add(stack_t **stack, int line);
void nop(stack_t **stack, unsigned int counter);

#endif /* LISTS_H */
