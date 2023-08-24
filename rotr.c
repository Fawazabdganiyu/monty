#include "monty.h"

/**
 * rotr - rotates the stack to the bottom.
 * @stack: A pointer to the stack list pointer
 * @line_number: The line number where the opcode was found
 *
 * Description: The last element of the stack becomes
 *	the top element of the stack
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;

	if (*stack && (*stack)->next->next)
	{
		temp = *stack;
		while (temp->next)
			temp = temp->next;

		(*stack)->prev = temp->prev;
		temp->prev->next = *stack;
		temp->prev = NULL;
		temp->next = (*stack)->next;
		(*stack)->next->prev = temp;
		(*stack)->next = NULL;
		*stack = temp;
	}
}
