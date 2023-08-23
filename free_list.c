#include "monty.h"

/**
 * free_list - frees the allocated stack list
 */
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
