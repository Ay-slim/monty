#include "monty.h"

/**
 * push - Push a node to the stack
 * @head: Pointer to pointer to stack head
 * @line: Monty bytecode line
 * Return: Nothing
 */
void push(stack_t **head, unsigned int line)
{
	int i = 0;
	int j = 0;
	int bit = 0;

	if (state.args)
	{
		if (state.args[0] == '-')
			j++;
		while (state.args[j] != '\0')
		{
			if (state.args[j] > 57 || state.args[j] < 48)
				bit = 1;
			j++;
		}
		if (bit == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line);
			fclose(state.bfr);
			free(state.info);
			free_list(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line);
		fclose(state.bfr);
		free(state.info);
		free_list(*head);
		exit(EXIT_FAILURE);
	}
	i = atoi(state.args);
	if (state.is_queue == 0)
		push_stack(head, i);
	else
		push_queue(head, i);
}

/**
 * pall - Print all the values on the stack starting from the stop
 * @head: Pointer to stack head
 * @line: Monty bytecode line
 * Return: Nothing
 */
void pall(stack_t **head, unsigned int line)
{
	stack_t *tmp = *head;
	(void)line;

	if (!tmp)
		return;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pchar - Print character
 * @head: Pointer to stack head
 * @line: Monty bytecode line
 * Return: Nothing
 */
void pchar(stack_t **head, unsigned int line)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line);
		fclose(state.bfr);
		free(state.info);
		free_list(*head);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n < 0 || (*head)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line);
		fclose(state.bfr);
		free(state.info);
		free_list(*head);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%c\n", (char)(*head)->n);
	}
}
