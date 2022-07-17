#include "monty.h"

/**
 * push - pushes an element to the stack
 * @head: head pointer (at the bottom of the stack)
 * @line: bytecode line number
 * Return: Nothing
 */
void push(stack_t **head, unsigned int line)
{
	stack_t *new;

	if (head == NULL)
	{
		printf("L%u: usage: push integger\n", line);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		printf("Error: malloc failed\n");
		free_stack(head, line);
		exit(EXIT_FAILURE);
	}

	new->n = variable.value;
	new->prev = NULL;
	new->next = *head;

	if (*head != NULL)
	{
		(*head)->prev = new;
	}
	*head = new;
}

/**
 * pop - popa the element at the top of the stack
 * @head: head of list
 * @line: bytecode line number
 * Return: nothing
 */
void pop(stack_t **head, unsigned int line)
{
	if (head == NULL || *head == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
	}
	if ((*head)->next != NULL)
	{
		*head = (*head)->next;
		variable.value = (*head)->n;
		free((*head)->prev);
		(*head)->prev = NULL;
	}
	else
	{
		free(*head);
		*head = NULL;
	}
}
