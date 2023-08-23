#include "monty.h"

/**
 * malloc_failed - handles when malloc fails
 */
void malloc_failed(void)
{
	dprintf(2, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}
