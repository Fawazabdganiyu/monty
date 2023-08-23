#include "monty.h"

void pop(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);

/**
 * pop - removes the top element of the stack.
 * @stack: A pointer to the stack list pointer
 * @line_number: The line number where the opcode was found
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * pint - prints the value at the top of the stack, followed by a new line.
 * @stack: A pointer to the stack list pointer
 * @line_number: The line number where the opcode was found
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack != NULL)
		printf("%d\n", (*stack)->n);
	else
	{
		dprintf(2, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}


/**
 * pall - prints the stack list
 * @stack: A pointer to the address of the top of the stack list
 * @line_number: A line where an opcode is found
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	temp = *stack;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}


/**
 * push - pushs an integer to stack list
 * @stack: A pointer to the stack list pointer
 * @line_number: The line number where the opcode was found
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
