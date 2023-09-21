#include "monty.h"
/**
 * pint - prints the value at the top of the stack
 * @stack: a pointer to stack
 * @line_number: the line number
 */

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	if (!top)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%d\n", top->n);
	}
}
