#include "monty.h"

/**
 * pall - prints the stack list
 */
void pall(void)
{
	stack_t *temp;

	if (stack != NULL)
	{
		temp = stack;
		while (temp)
		{
			printf("%d\n", temp->n);
			temp = temp->next;
		}
	}
}
