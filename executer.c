#include "monty.h"

/**
 * execute_ops - executes according to operation code
 * @stack: pointer to pointer to stack
 * @line: line number
 * @token: tokenized input
 *
 * Return: nothing
 */
void execute_ops(stack_t **stack, unsigned int line, char *token)
{
	int i = 0;
	instruction_t op[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"nop", nop},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{NULL, NULL}
	};

	while (op[i].opcode != NULL)
	{
		if (strcmp(token, op[i].opcode) == 0)
		{
			op[i].f(stack, line);
			return;
		}
		i++;
	}

	printf("L%d: unknown intruction %s\n", line, token);
	free_stack(stack, line);
	exit(EXIT_FAILURE);
}
