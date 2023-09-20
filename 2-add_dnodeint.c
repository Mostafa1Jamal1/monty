#include "monty.h"
/**
 * add_dnodeint - adds a new node at the beginning of stack.
 * @head: a pointer to the head of the stack
 * @n: the value to add in the new stack
 * Return: the address of the new element, or NULL if it failed
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{	/* Allocate memory for new node */
	stack_t *new = malloc(sizeof(stack_t));
	/* Check if allocation succeeded */
	if (new == NULL)
		exit_mallocfail(head);
	/* Assign the value to the node */
	new->n = n;
	new->prev = NULL;
	/* Make the new node the head */
	if (head)
	{
		new->next = *head;
		if (*head)
			(*head)->prev = new;
		*head = new;
	}
	else
		new->next = NULL;
	return (new);
}
