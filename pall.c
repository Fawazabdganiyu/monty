#include "monty.h"

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
