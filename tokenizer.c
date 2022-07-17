#include "monty.h"

/**
 * tokenizer - tokenizes an input string
 * @input: string to be tokenized
 * @stack: pointer to pointer to stack
 * @line: line number to command
 *
 * Return: nothing
 */
void tokenizer(char *input, stack_t **stack, unsigned int line)
{
	char *token = NULL, *tokens = NULL;

	token = strtok(input, " ");
	if (!token || *token == '\n' || *token == '#' || *token == ' ')
		return;
	if (strcmp(token, "push") == 0)
	{
		tokens = token;
		token = strtok(NULL, " ");
		if (check_digit(token) == 0)
		{
			dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line);
			free_stack(stack, line);
			exit(EXIT_FAILURE);
		}
		variable.value = atoi(token);
		execute_ops(stack, line, tokens);
	}
	else
		execute_ops(stack, line, token);
}

