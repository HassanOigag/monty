#include "monty.h"

/**
 * malloc_error - prints the error of malloc
 * Return: nothing
*/

void malloc_error(void)
{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
}

/**
 * push - pushes a number to the stack
 * @stack: the address of the top
 * @n: the number to push to the top
 * Return: nothing
*/

void push(stack_t **stack, int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
		malloc_error();
	new->n = n;
	new->next = *stack;
	if (*stack)
		(*stack)->prev = new;
	*stack = new;
	new->prev = NULL;
}

/**
 * print_stack - prints the stack
 * @stack: the stack to print
 * Return: nothing
*/

void print_stack(stack_t *stack)
{
	stack_t *tmp = stack;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * free_stack - free the stack
 * @stack: the stack to free
 * Return: returns nothing
*/

void free_stack(stack_t *stack)
{
	stack_t *tmp = stack;

	while (tmp && tmp->next)
	{
		tmp = tmp->next;
		free(tmp->prev);
	}
	if (tmp)
		free(tmp);
}

/**
 * pop - removes the top element
 * @stack: the stack
 * Return: nothing
*/

void pop(stack_t **stack)
{
	stack_t *tmp;

	if (!*stack)
		return;
	tmp = *stack;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(tmp);
}


