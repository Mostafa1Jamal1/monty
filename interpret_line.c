#include "monty.h"
/**
 * interpret_line - interpret a line in opened file
 * @file: file streame of the opened file
 * @stack: a pointer to stack
 * @line_number: the line number
 * Return: 1 (Success)
 * or 0 on end of file
 * any failure will exit the program
 */
int interpret_line(FILE *file, stack_t **stack, unsigned int line_number)
{
	char *line = NULL;
	size_t n = 0;
	char *opcode;
	void (*func)(stack_t **stack, unsigned int line_number);
	/* End of file check and get line if not*/
	if (getline(&line, &n, file) == -1)
	{
		free(line);
		return (0);
	}
	opcode = strtok(line, " \n");
	/* Empty line check */
	if (!opcode)
	{
		free(line);
		return (1);
	}
	/* Get function and check */
	func = get_func(opcode);
	if (!func)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		fclose(global.file);
		free_stack(*stack);
		free(line);
		exit(EXIT_FAILURE);
	}
	/* Call the function */
	func(stack, line_number);
	free(line);
	return (1);
}
