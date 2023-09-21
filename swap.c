#include "monty.h"
/**
 * swap - swaps the top two elements of the stack.
 * @stack: a pointer to stack
 * @line_number: the line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack, *next;
	int temp;

	if (top)
	{
		next = top->next;
		if (next)
		{
			temp = top->n;
			top->n = next->n;
			next->n = temp;
			return;
		}
	}
	fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}
