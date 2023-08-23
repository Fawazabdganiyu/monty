#include "monty.h"

/***/
void free_list(void)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
	stack = NULL;
}
