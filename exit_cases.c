#include "monty.h"
/**
 * exit_usagefail - exit in usage failure
 */
void exit_usagefail(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * exit_openfail - exit in open file failure
 * @filename: the file name
 */
void exit_openfail(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	exit(EXIT_FAILURE);
}

/**
 * exit_mallocfail - exit in malloc failure
 * @stack: a pointer to stack
 */
void exit_mallocfail(stack_t **stack)
{
	free_stack(*stack);
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}
