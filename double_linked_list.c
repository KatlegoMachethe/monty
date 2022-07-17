#include "monty.h"

/**
 * add_end_node - add node at the end of doubly linked list
 * @head: pointer to head of stack
 * @n: data to add
 *
 * Return: zer0
 */
int add_end_node(stack_t **head, int n)
{
	stack_t *new = NULL;

	if (!head)
		return (-1);

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = n;
	if (*head == NULL)
	{
		*head = new;
		new->next = NULL;
		new->prev = NULL;
	}
	else
	{
		new->next = *head;
		(*head)->prev = new;
		*head = new;
	}
	return (0);
}

/**
 * del_end_node - delete end node of doubly linked list
 * @head: pointer to head
 *
 * Return: nothing
 */
void del_end_node(stack_t **head)
{
	stack_t *del = NULL;

	del = *head;
	if ((*head)->next == NULL)
	{
		*head = NULL;
		free(del);
	}
	else
	{
		*head = (*head)->next;
		(*head)->prev = NULL;
		free(del);
	}
}

/**
 * free_doubly_list - frees a doubly linked list with only integer data
 * @head: pointer to head of list
 *
 * Return: nothing
 */
void free_doubly_list(stack_t **head)
{
	if (!head)
		return;
	while (*head && (*head)->next)
	{
		*head = (*head)->next;
		free((*head)->prev);
	}
	free((*head)->prev);
}
