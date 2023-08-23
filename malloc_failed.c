#include "monty.h"

/***/
void malloc_failed(void)
{
	dprintf(2, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}
