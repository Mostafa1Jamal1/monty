#include "monty.h"
/**
 * monty_mul - multiplies the second top element of the stack
 * with the top element of the stack.
 * @stack: a pointer to stack
 * @line_number: the line number
 */
void monty_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack, *next;

	if (top)
	{
		next = top->next;
		if (next)
		{
			next->n *= top->n;
			free(*stack);
			*stack = next;
			next->prev = NULL;
			return;
		}
	}
	fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}
