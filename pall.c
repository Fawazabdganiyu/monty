#include "monty.h"

/***/
void pall(void)
{
	while (stack)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
	}
}
