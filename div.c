#include "monty.h"
/**
 * div - divides the second top element of the stack
 * by the top element of the stack.
 * @stack: a pointer to stack
 * @line_number: the line number
 */
void monty_div(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack, *next;

	if (top)
	{
		next = top->next;
		if (next)
		{
			if (top->n == 0)
			{
				fprintf(stderr, "L%u: division by zero\n", line_number);
				exit(EXIT_FAILURE);
			}
			next->n /= top->n;
			free(*stack);
			*stack = next;
			next->prev = NULL;
			return;
		}
	}
	fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}
