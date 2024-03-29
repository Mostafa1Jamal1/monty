#include "monty.h"
/**
 * get_func - get the function of the opcode
 * @opcode: the opcode
 * Return: function pointer of the opcode
 * or NULL if not found
 */
void (*get_func(char *opcode))(stack_t **stack, unsigned int line_number)
{
	int i;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", monty_div},
		{"mul", monty_mul},
		{"mod", monty_mod},
		{"pchar", monty_pchar},
		{NULL, NULL}
	};

	for (i = 0; (instructions + i)->opcode != NULL; i++)
	{
		if (strcmp(opcode, (instructions + i)->opcode) == 0)
			return ((instructions + i)->f);
	}
	return (NULL);
}
