#include "monty.h"

/**
 * check_digit - checks if element is nemeric
 * @token: string to be checked
 *
 * Return: 1 for number, 0 otherwise.
 */
int check_digit(char *token)
{
	if (!token)
		return (0);
	if (*token == '-')
		token++;
	while (*token != '\0')
	{
		if (!isdigit(*token))
			return (0);
		token++;
	}
	token++;
	return (1);
}
