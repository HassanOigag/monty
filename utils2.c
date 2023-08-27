#include "monty.h"

/**
 * partial_free - free some stuff
 * @l: line
 * @w: words
 * @msg: message
 * @ln: line number
 * Return: nothing
*/
void partial_free(char *l, char **w, char *msg, int ln)
{
	fprintf(stderr, "L%d: %s\n", ln, msg);
	free_array(w);
	free(l);
	exit(EXIT_FAILURE);
}

/**
 * full_free - free everything
 * @monty: monty data
 * Return: nothing
*/

void full_free(monty_t *monty)
{
	free_array(monty->words);
	free(monty->line);
	free_stack(monty->my_stack);
	exit(EXIT_FAILURE);
}

/**
 * do_op - do operation
 * @monty: monty data
*/

void do_op(monty_t *monty)
{
	if (ft_strcmp(monty->words[0], "push") == 0)
	{
		if (!isstrnumber(monty->words[1]))
		{
			fprintf(stderr, "L%d: usage: push integer\n", monty->line_number);
			full_free(monty);
		}
		push(&monty->my_stack, atoi(monty->words[1]));
	}
	else if (ft_strcmp(monty->words[0], "pall") == 0)
		print_stack(monty->my_stack);
	else if (ft_strcmp(monty->words[0], "pint") == 0)
	{
		if (!monty->my_stack)
			partial_free(monty->line,
				monty->words, "can't pint, stack empty", monty->line_number);
		printf("%d\n",	monty->my_stack->n);
	}
	else if (ft_strcmp(monty->words[0], "pop") == 0)
	{
		if (!monty->my_stack)
			partial_free(monty->line,
			monty->words, "can't pop an empty stack", monty->line_number);
		pop(&monty->my_stack);
	}
	else if (ft_strcmp(monty->words[0], "swap") == 0)
	{
		if (!monty->my_stack || !monty->my_stack->next)
			partial_free(monty->line,
				monty->words, "can't swap, stack too short", monty->line_number);
		swap(&monty->my_stack);
	}
	else if (ft_strcmp(monty->words[0], "add") == 0)
	{
		if (!monty->my_stack || !monty->my_stack->next)
			partial_free(monty->line,
				monty->words, "can't add, stack too short", monty->line_number);
		add(&monty->my_stack);
	}
	free_array(monty->words);
}
