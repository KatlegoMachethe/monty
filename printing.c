#include "monty.h"

/**
 * nop - does absolutely fokol
 * @head: pointer to header
 * @line: number of line
 *
 * Return: nothinh
 */
void nop(stack_t **head, unsigned int line)
{
	(void) head;
	(void) line;
}

/**
 * pall - print value on stack, from top to bottom
 * @head: pointer to the head
 * @line: number of line of node
 *
 * Return: nothing
 */
void pall(stack_t **head, unsigned int line)
{
	stack_t *tmp = NULL;

	if (head == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: invalid stack\n", line);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * swap - swaps the two elements at the top of the stack
 * @head: node to be swapped
 * @line: number of line
 *
 * Return: nothing
 */
void swap(stack_t **head, unsigned int line)
{
	int i;

	if (*head == NULL || head == NULL || (*head)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n", line);
		free_stack(head, line);
		exit(EXIT_FAILURE);
	}
	i = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = i;
}

/**
 * pint - print the value at the top of the stack
 * @head: pointer to head of stack
 * @line: number of the line
 *
 * Return: nothing
 */
void pint(stack_t **head, unsigned int line)
{
	if (!head || !*head)
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
