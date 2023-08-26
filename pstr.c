#include "monty.h"

/**
 * pstr - print all integer as characters in a stack
 * @stack: the stack
 * @line_number: line number
 *
 * Return: void
 */

void pstr(stack_t **stack, unsigned int line_number)
{
	int num;
	stack_t *temp;

	(void)line_number;

	if (*stack == NULL)
	{
		printf("\n");
		return;
	}

	temp = *stack;

	while (temp != NULL)
	{
		num = temp->n;
		if (num <= 0 || num > 127)
<<<<<<< HEAD
		{
			dprintf(2, "Out of range\n");
=======
>>>>>>> 954340cfe8c97757e36ebd504bdf5b8157c7d086
			break;

		printf("%c", num);
		temp = temp->next;
	}
	printf("\n");
}
