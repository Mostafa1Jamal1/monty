#include "monty.h"
/**
 * main - Monty interpreter
 * @argc: number of arguments (should be 2)
 * @argv: an array of string arguments
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */

int main(int argc, char **argv)
{
	unsigned int line_number = 1;
	stack_t *stack = NULL;
	/* Handle usage failure */
	if (argc != 2)
		exit_usagefail();
	/* Handle open file */
	global.file = fopen(argv[1], "r");
	if (!global.file)
		exit_openfail(argv[1]);
	/* Handle interpreting lines */
	while (interpret_line(global.file, &stack, line_number))
		line_number++;
	/* Finished file */
	fclose(global.file);
	free_stack(stack);
	return (EXIT_SUCCESS);
}
