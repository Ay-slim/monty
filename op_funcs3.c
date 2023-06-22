#include "monty.h"

/**
 * sub - Subtract the top element from the one below
 * @head: Pointer to stack head
 * @line: Monty bytecode line
 * Return: Nothing
 */
void sub(stack_t **head, unsigned int line)
{
	stack_t *tmp = *head;
	int diff;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line);
		fclose(state.bfr);
		free(state.info);
		free_list(*head);
		exit(EXIT_FAILURE);
	}
	else
	{
		diff = (*head)->next->n - (*head)->n;
		(*head)->next->n = diff;
		(*head) = (*head)->next;
		(*head)->prev = NULL;
		free(tmp);
	}
}
