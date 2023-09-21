#ifndef MONTY_H
#define MONTY_H
#define  _GNU_SOURCE

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct globalvariable - struct of global variables
 * @file: file stream
 */
typedef struct globalvariable
{
	FILE *file;
} global_t;

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


/* Prototypes */
stack_t *add_dnodeint(stack_t **head, const int n);
void free_stack(stack_t *stack);
void (*get_func(char *opcode))(stack_t **stack, unsigned int line_number);
int interpret_line(FILE *file, stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
/*************************************/

/* Prototypes of exit_cases.c file */
void exit_usagefail(void);
void exit_openfail(char *filename);
void exit_instrucionfail(unsigned int ln, char *opcode, stack_t **stack);
void exit_mallocfail(stack_t **stack);
/*************************************/

extern global_t global;

#endif /* #ifndef MONTY_H */
