#include "monty.h"

/**
 * free_stack - frees the whole stack
 * @stack: stack to be freed
 * @line: line number
 *
 * Return: nothing
 */
void free_stack(stack_t **stack, unsigned int line)
{
	if (stack == NULL)
		return;
	while (*stack != NULL)
		pop(stack, line);
}
