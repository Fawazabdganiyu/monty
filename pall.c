#include "monty.h"

/***/
void pall(void)
{
	stack_t *temp;

	temp = stack;
	while (temp)
	{
		printf("%d\n", stack->n);
		temp = temp->next;
	}
}
