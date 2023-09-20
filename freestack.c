#include "monty.h"
/**
 * free_stack - free the stack
 * @stack: the stack to free
 */
void free_stack(stack_t *stack)
{
	stack_t *next;

	while (stack)
	{
		next = stack->next;
		free(stack);
		stack = next;
	}
}
