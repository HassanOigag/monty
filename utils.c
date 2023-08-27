#include "monty.h"

/**
 * remove_new_line - removes the \n from the line
 * @s: the line in hand
 * Return: returns nothing
*/
void remove_new_line(char **s)
{
	int i = 0;

	if (!*s)
		return;
	while ((*s)[i] && (*s)[i] != '\n')
		i++;
	if ((*s)[i] == '\n')
		(*s)[i] = '\0';
}

/**
 * is_line_empty - checks if the line is empty
 * @line: the line to check
 * Return: returns 1 if line is empty else 0
*/

int is_line_empty(char *line)
{
	int i = 0;

	if (!line)
		return (1);
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

/**
 * isstrnumber - checks if a string is a number
 * @str: the string in hand
 * Return: 1 if the string is all numbers else 0 is returned
*/

int isstrnumber(char *str)
{
	int i = 0;

	if (!str)
		return (0);
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

/**
 * ft_strcmp - compares two strings
 * @s1: the first string
 * @s2: the second string
 * Return: return the difference of their ascii code
*/

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

/**
 * is_valid_op - checks if and operation is valid
 * @opcode: the code of the operation
 * Return: 1 if true else 0
*/

int is_valid_op(char *opcode)
{
	char *opcodes[] = {"push", "pall",
		"pint", "pop", "swap", "add", "nop", NULL};
	int i = 0;

	if (!opcode)
		return (0);
	while (opcodes[i])
	{
		if (ft_strcmp(opcodes[i], opcode) == 0)
			return (1);
		i++;
	}
	return (0);
}
