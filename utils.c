#include "monty.h"

/**
 * push_queue - Enqueue a value by appending it to the tail of a dll
 * @head: Pointer to pointer to head node
 * @data: Data to push
 * Return: Nothing
 */
void push_queue(stack_t **head, int data)
{
	stack_t *tmp;
	stack_t *new = malloc(sizeof(stack_t));

	if (!new)
		printf("Error\n");
	tmp = *head;
	new->n = data;
	new->next = NULL;
	if (!tmp)
	{
		*head = new;
		(*head)->prev = NULL;
		return;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}

/**
 * push_stack - Push a value to a stack by appending it to a dll head
 * @head: Pointer to pointer to head node
 * @data: Data to push
 * Return: Nothing
 */
void push_stack(stack_t **head, int data)
{
	stack_t *new = malloc(sizeof(stack_t));
	stack_t *tmp = *head;

	if (!new)
	{
		printf("Error\n");
		exit(0);
	}
	if (tmp)
		tmp->prev = new;
	new->next = tmp;
	new->prev = NULL;
	new->n = data;
	*head = new;
}

/**
 * free_list - Free memory allocated to a stack_t list
 * @head: Pointer to the head element
 * Return: Nothing
 */
void free_list(stack_t *head)
{
	stack_t *tmp;

	tmp = head;
	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
