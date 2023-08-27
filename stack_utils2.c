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
