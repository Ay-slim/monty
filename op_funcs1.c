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

/**
 * pop - Remove the top element of the stack
 * @head: Pointer to stack head
 * @line: Monty bytecode line
 * Return: Nothing
 */
void pop(stack_t **head, unsigned int line)
{
	stack_t *tmp = *head;
	(void)line;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		fclose(state.bfr);
		free(state.info);
		free_list(*head);
		exit(EXIT_FAILURE);
	}
	else
	{
		*head = (*head)->next;
		if (*head)
		{
			(*head)->prev = NULL;
			free(tmp);
		}
	}
}

/**
 * swap - Swap the top two elements of the stack
 * @head: Pointer to stack head
 * @line: Monty bytecode line
 * Return: Nothing
 */
void swap(stack_t **head, unsigned int line)
{
	stack_t *tmp = malloc(sizeof(stack_t));
	stack_t *head_clone = *head;
	(void)line;

	if (*head == NULL || (*head)->next == NULL || !tmp)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		fclose(state.bfr);
		free(state.info);
		free_list(*head);
		exit(EXIT_FAILURE);
	}
	else
	{
		tmp->next = (*head)->next->next;
		tmp->n = (*head)->n;
		*head = (*head)->next;
		(*head)->prev = NULL;
		(*head)->next = tmp;
		tmp->prev = *head;
		if (tmp->next)
		{
			tmp->next->prev = tmp;
		}
		free(head_clone);
	}
}

/**
 * add - Add the top two elements of the stack
 * @head: Pointer to stack head
 * @line: Monty bytecode line
 * Return: Nothing
 */
void add(stack_t **head, unsigned int line)
{
	stack_t *tmp = *head;
	int sum;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		fclose(state.bfr);
		free(state.info);
		free_list(*head);
		exit(EXIT_FAILURE);
	}
	else
	{
		sum = (*head)->n + (*head)->next->n;
		(*head)->next->n = sum;
		(*head) = (*head)->next;
		(*head)->prev = NULL;
		free(tmp);
	}
}
