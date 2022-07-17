#include "monty.h"

/**
 * _pchar - print the character at the top of the stack
 * @head: pointer to the stack top
 * @line: line number
 *
 * Return: nothing
 */
void _pchar(stack_t **head, unsigned int line)
{
	if (head == NULL || *head == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pchar, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	if (isascii(variable.value))
		printf("%c\n", variable.value);
	else
	{
		dprintf(STDERR_FILENO, "L%d: can't pchar, value out of range\n", line);
		exit(EXIT_FAILURE);
	}
}

/**
 * _pstr - prints string from the top of the stack
 * @head: pointer to the top of the stack
 * @line: line number
 *
 * Return: nothing
 */
void _pstr(stack_t **head, unsigned int line)
{
	stack_t *str;
	(void) line;

	if (head == NULL || *head == NULL || variable.value == 0)
	{
		printf("\n");
		return;
	}
	str = *head;

	while (str != NULL && str->n != 0 && isascii(str->n))
	{
		printf("%c", str->n);
		str = str->next;
	}
	printf("\n");
}

/**
 * _rotl - rotates the stack to the top
 * @head: pointer to stack
 * @line: line number
 *
 * Return: nothing
 */
void _rotl(stack_t **head, unsigned int line)
{
	stack_t *tmp;
	(void) line;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return;
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *head;
	(*head)->prev = tmp;
	*head = (*head)->next;
	(*head)->prev = NULL;
	tmp->next->next = NULL;
}

/**
 * _rotr - rotates the stack from the bottom
 * @head: pointer to stack top
 * @line: line number
 *
 * Return: nothing
 */
void _rotr(stack_t **head, unsigned int line)
{
	stack_t *tmp;
	(void) line;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return;

	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *head;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*head)->prev = tmp;
	*head = tmp;
}
