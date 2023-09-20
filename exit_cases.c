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
 * exit_instrucionfail - exit in invalid instruction
 * @ln: the line number
 * @opcode: the invalid instruction
 * @stack: a pointer to stack
 */
void exit_instrucionfail(unsigned int ln, char *opcode, stack_t **stack)
{
	fclose(global.file);
	free_stack(*stack);
	fprintf(stderr, "L%u: unknown instruction %s\n", ln, opcode);
	exit(EXIT_FAILURE);
}

/**
 * exit_mallocfail - exit in malloc failure
 * @stack: a pointer to stack
 */
void exit_mallocfail(stack_t **stack)
{
	fclose(global.file);
	free_stack(*stack);
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}
