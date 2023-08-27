#include "monty.h"

/**
 * full_free - free everything
 * @my_stack: the stack
 * @line: the line
 * @words: array of words
 * Return: nothing
*/

void full_free(stack_t *my_stack, char *line, char **words)
{
	free_array(words);
	free(line);
	free_stack(my_stack);
	exit(EXIT_FAILURE);
}

/**
 * do_op - do operation
 * @my_stack: the stack
 * @line: the line
 * @line_number: the line number
*/

void do_op(stack_t **my_stack, char *line, int line_number)
{
	char **words = split(line, ' ');

	if (!words)
		malloc_error();
	/* get_operation(words[0]).f(my_stack, line_number);*/
	if (ft_strcmp(words[0], "push") == 0)
	{
		if (!isstrnumber(words[1]))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			full_free(*my_stack, line, words);
		}
		push(my_stack, atoi(words[1]));
	}
	else if (ft_strcmp(words[0], "pall") == 0)
		print_stack(*my_stack);
	else if (ft_strcmp(words[0], "pint") == 0)
	{
		if (!*my_stack)
		{
			fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
			free_array(words);
			free(line);
			exit(EXIT_FAILURE);
		}
		printf("%d\n", (*my_stack)->n);
	}
	else if (ft_strcmp(words[0], "pop") == 0)
	{
		if (!*my_stack)
		{
			fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
			free_array(words);
			free(line);
			exit(EXIT_FAILURE);
		}
		pop(my_stack);
	}
	free_array(words);
}
