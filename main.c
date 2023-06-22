#define _GNU_SOURCE
#include "monty.h"
state_t state = {NULL, NULL, NULL, 0};
/**
 * engine - The core part of the app that calls the op code
 * @head: Pointer to pointer to stack head
 * @line: Bytecode file line
 * @bfr: Pointer to monty bytecode file
 * @info: Info within bytecode line
 * Return: 1 if operation occurred 0 otherwise
 */
int engine(stack_t **head, unsigned int line, FILE *bfr, char *info)
{
	instruction_t opmap[] = {
		{"push", push}, {"pall", pall}, {"pint", pint}, {"pop", pop},
		{"swap", swap}, {"add", add}, {"nop", nop}, {"sub", sub},
		{"div", divisor}, {"mul", mul}, {"mod", mod}, {"pchar", pchar},
		{"pstr", pstr}
	};
	unsigned int n = 0;
	char *instr;

	instr = strtok(info, " \n\t");
	if (instr && instr[0] == '#')
		return (0);
	state.args = strtok(NULL, " \n\t");
	while (opmap[n].opcode && instr)
	{
		if (strcmp(instr, opmap[n].opcode) == 0)
		{
			opmap[n].f(head, line);
			return (0);
		}
		n++;
	}
	if (instr && opmap[n].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line, instr);
		fclose(bfr);
		free(info);
		free_list(*head);
		exit(EXIT_FAILURE);
	}
	return (1);
}

/**
 * main - Main function for executing ops functions on monty bytecode file
 * @argc: Number of args
 * @argv: Arguments to the monty interpreter (index 1 is bytecode file)
 * Return: 0 if successful
 */
int main(int argc, char **argv)
{
	FILE *bfr;
	stack_t *head = NULL;
	char *info;
	unsigned int line = 0;
	size_t len = 0;
	ssize_t line_bfr = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	bfr = fopen(argv[1], "r");
	state.bfr = bfr;
	if (!bfr)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (line_bfr > 0)
	{
		info = NULL;
		line_bfr = getline(&info, &len, bfr);
		state.info = info;
		line++;
		if (line_bfr > 0)
		{
			engine(&head, line, bfr, info);
		}
		free(info);
	}
	free_list(head);
	fclose(bfr);
	return (0);
}
