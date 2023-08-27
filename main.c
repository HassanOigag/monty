#include "monty.h"

/**
 * parse_line - parses a line
 * @my_stack: the stack
 * @line: the line to parse
 * @line_number: line number
 * Return: nothing
*/

void parse_line(stack_t **my_stack, char *line, int line_number)
{
	char **words = split(line, ' ');

	if (!words)
		malloc_error();
	if (!is_valid_op(words[0]))
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, words[0]);
		free_array(words);
		free(line);
		free_stack(*my_stack);
		exit(EXIT_FAILURE);
	}
	free_array(words);
	do_op(my_stack, line, line_number);
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
	char *line;
	int fd;
	int line_number = 1;
	stack_t *my_stack = NULL;

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
		line = get_next_line(fd);
		if (!line)
			break;
		if (!is_line_empty(line))
		{
			remove_new_line(&line);
			parse_line(&my_stack, line, line_number);
		}
		free(line);
		line_number++;
	}
	close(fd);
	return (0);
}
