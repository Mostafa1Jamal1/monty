#include "monty.h"
/**
 * push - add node to stack
 * @stack: a pointer to stack
 * @line_number: the line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	int number;
	char *num_str = strtok(NULL, " \n");

	if (num_str != NULL)
	{
		if (isdigit(num_str[0]) != 0)
		{
			number = atoi(num_str);
			add_dnodeint(stack, number);
			return;
		}
	}
	free_stack(*stack);
	free(global.line);
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	exit(EXIT_FAILURE);
}
