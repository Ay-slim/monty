#include "monty.h"
/**
 * rotr - Flip stack
 * @head: Pointer to stack head
 * @line: Monty bytecode line
 * Return: Nothing
 */
void rotr(stack_t **head, unsigned int line)
{
	stack_t *tmp1 = *head;
	stack_t *tail_clone = malloc(sizeof(stack_t));
	(void)line;

	if (!tail_clone)
		return;
	while (tmp1->next)
	{
		tmp1 = tmp1->next;
	}
	tmp1->prev->next = NULL;
	tail_clone->n = tmp1->n;
	tail_clone->next = *head;
	tail_clone->prev = NULL;
	(*head)->prev = tail_clone;
	*head = tail_clone;
	free(tmp1);
}
