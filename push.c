#include "monty.h"

/**
 * push - pushs an integer to stack list
 * @stack: A pointer to the stack list pointer
 * @line_number: The line number where the opcode occure
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	(void)line_number;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		malloc_failed();

	new->n = n;
	new->prev = NULL;
	new->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}
