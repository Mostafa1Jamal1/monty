#include "monty.h"
/**
 * sub - subtracts the top element of the stack
 * from the second top element of the stack.
 * @stack: a pointer to stack
 * @line_number: the line number
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack, *next;

	if (top)
	{
		next = top->next;
		if (next)
		{
			next->n -= top->n;
			next = top->next;
			free(*stack);
			if (next)
				next->prev = NULL;
			return;
		}
	}
	fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}
