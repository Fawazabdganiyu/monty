#include "monty.h"

/**
 * pchar - prints integer at the top of stack as character
 * @stack: the stack
 * @line_number
 *
 * Return: void
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	int num;
	char c;

	if (*stack == NULL)
	{
		dprintf(2, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	num = (*stack)->n;
	if (num >= 0 && num < 128)
	{
		c = num + 0;
		printf("%c\n", c);
	}
	else
	{
		dprintf(2, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
}
