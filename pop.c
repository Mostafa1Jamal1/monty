#include "monty.h"
/**
 * pop -  removes the top element of the stack.
 * @stack: a pointer to stack
 * @line_number: the line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack, *next;

	if (!top)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);	
	}
	next = top->next;
	free(*stack);
	*stack = next;
	if (!next)
		next->prev = NULL;
}
