#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct state_s - Data structure to hold the current state of monty file
 * @bfr: A pointer to the monty file
 * @args: Tokenized arguments from monty file
 * @info: Information contained within each monty file line
 * @is_queue: Bit to indicate whether we're handling a stack or queue
 *
 * Description: Propagate bytecode state through the app
 */
typedef struct state_s
{
	FILE *bfr;
	char *args;
	char *info;
	int is_queue;
} state_t;
extern state_t state;
void push(stack_t **head, unsigned int line);
void pall(stack_t **head, unsigned int line);
void pint(stack_t **head, unsigned int line);
void pop(stack_t **head, unsigned int line);
void push_stack(stack_t **head, int data);
void push_queue(stack_t **head, int data);
void free_list(stack_t *head);
int engine(stack_t **head, unsigned int line, FILE *bfr, char *info);

#endif
