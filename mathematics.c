#include "monty.h"

/**
 * add - function to add two elements on stack
 * @stack: the stack
 * @line: number of line
 *
 * Return: nothing
 */
void add(stack_t **stack, unsigned int line)
{
	int adding;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", line);
		free_stack(stack, line);
		exit(EXIT_FAILURE);
	}

	adding = variable.value;
	pop(stack, line);
	adding += variable.value;
	pop(stack, line);
	variable.value = adding;
	push(stack, line);
}

/**
 * sub - subtracts the two top elements of the stack
 * @stack: the stack
 * @line: number of line
 *
 * Return: nothing
 */
void sub(stack_t **stack, unsigned int line)
{
	int subtract;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't sub, stack too short\n", line);
		free_stack(stack, line);
		exit(EXIT_FAILURE);
	}

	subtract = variable.value;
	pop(stack, line);
	subtract = variable.value - subtract;
	pop(stack, line);
	variable.value = subtract;
	push(stack, line);
}

/**
 * _div - divide the second top element of the stack with the top one
 * @stack: The stack
 * @line: munber of line
 *
 * Return: nothing
 */
void _div(stack_t **stack, unsigned int line)
{
	int divide;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't div, stack too short\n", line);
		free_stack(stack, line);
		exit(EXIT_FAILURE);
	}
	if (variable.value == 0)
	{
		dprintf(STDERR_FILENO, "L%d: division by zero\n", line);
		free_stack(stack, line);
		exit(EXIT_FAILURE);
	}

	divide = variable.value;
	pop(stack, line);
	divide = variable.value / divide;
	pop(stack, line);
	variable.value = divide;
	push(stack, line);
}

/**
 * _mul - multiplies second top element of stack with top element
 * @stack: the stack
 * @line: number of line
 *
 * Return: nothing
 */
void _mul(stack_t **stack, unsigned int line)
{
	int multiply;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't mul, stack too short\n", line);
		free_stack(stack, line);
		exit(EXIT_FAILURE);
	}

	multiply = variable.value;
	pop(stack, line);
	multiply = variable.value * multiply;
	pop(stack, line);
	variable.value = multiply;
	push(stack, line);
}

/**
 * _mod -computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @stack: stack
 * @line: number of line
 *
 * Return: nothing
 */
void _mod(stack_t **stack, unsigned int line)
{
	int rem;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't mod, stack too short\n", line);
		free_stack(stack, line);
		exit(EXIT_FAILURE);
	}
	if (variable.value == 0)
	{
		printf("L%d: division by zero\n", line);
		free_stack(stack, line);
		exit(EXIT_FAILURE);
	}

	rem = variable.value;
	pop(stack, line);
	rem = variable.value % rem;
	pop(stack, line);
	variable.value = rem;
	push(stack, line);
}
