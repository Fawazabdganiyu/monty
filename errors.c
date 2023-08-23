#include "monty.h"

void usage_error(void);
void open_error(char *file);

/**
 * usage_error - prints usage error message and exit
 */
void usage_error(void)
{
	dprintf(2, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * open_error - prints error message when a file can not be opened and exit
 * @file: The expected file to be interpreted
 */
void open_error(char *file)
{
	dprintf(2, "Error: Can't open file %s\n", file);
	exit(EXIT_FAILURE);
}
