#include "monty.h"

/**
 * pint - Print value at the top of the stack
 * @head: Pointer to stack head
 * @line: Monty bytecode line
 * Return: Nothing
 */
void pint(stack_t **head, unsigned int line)
{
	(void)line;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%d\n", (*head)->n);
	}
}
