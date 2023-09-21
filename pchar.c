#include "monty.h"
/**
 * monty_pchar - prints the value at the top of the stack
 * @stack: a pointer to stack
 * @line_number: the line number
 */

void monty_pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	if (!top)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (top->n >= 0 && top->n <= 255)
			printf("%c\n", top->n);
		else
		{
			fprintf(stderr, "L%u: can't pchar, value out of range", line_number);
			exit(EXIT_FAILURE);
		}
	}
}
