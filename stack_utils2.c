#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: the stack
 * Return: nothing
*/

void swap(stack_t **stack)
{
	int tmp;

	if (!*stack || !(*stack)->next)
		return;
	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}

/**
 * add - add two elements of the stack
 * @stack_t: the stack
 * Return: nothing
*/

void add(stack_t **stack_t)
{
	int sum;

	sum = (*stack_t)->n + (*stack_t)->next->n;
	pop(stack_t);
	(*stack_t)->n = sum;
}
