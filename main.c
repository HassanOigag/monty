#include "monty.h"

/**
 * parse_line - parses a line
 * @monty: the monty structure
 * Return: nothing
*/

void parse_line(monty_t *monty)
{
	monty->words = split(monty->line, ' ');

	if (!monty->words)
		malloc_error();
	if (!is_valid_op(monty->words[0]))
	{
		fprintf(stderr, "L%d: unknown instruction %s\n",
			monty->line_number, monty->words[0]);
		free_array(monty->words);
		free(monty->line);
		free_stack(monty->my_stack);
		exit(EXIT_FAILURE);
	}
	do_op(monty);
}

/**
 * main - the entry point of the programme
 * @argc: number of args
 * @argv: array of arguments
 * Return: 0 on success else 1
*/

int main(int argc, char **argv)
{
	char *monty_file;
	int fd;
	monty_t monty;

	monty.line_number = 1;
	monty.my_stack = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	monty_file = argv[1];
	fd = open(monty_file, O_RDONLY);
	if (fd < 0)
	{
		fprintf(stderr, "Error: Can't open file %s\n", monty_file);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		monty.line = get_next_line(fd);
		if (!monty.line)
			break;
		if (!is_line_empty(monty.line))
		{
			remove_new_line(&monty.line);
			parse_line(&monty);
		}
		free(monty.line);
		monty.line_number++;
	}
	close(fd);
	free_stack(monty.my_stack);
	return (0);
}
