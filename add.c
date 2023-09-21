#include "monty.h"
/**
 * add - adds the top two elements of the stack.
 * @stack: a pointer to stack
 * @line_number: the line number
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack, *next;

	if (top)
	{
		next = top->next;
		if (next)
		{
			next->n += top->n;
			next = top->next;
			free(*stack);
			*stack = next;
			if (next)
				next->prev = NULL;
			return;
		}
	}
	fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}
