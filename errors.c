#include "monty.h"

/**
 * push_err - handles error from push
 * @stack: A pointer to the head pointer of the stack list
 * @line_number: The line where the opcode is found
 */
void push_err(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * pall_err - handles error from pall
 * @stack: A pointer to the head pointer of the stack list
 * @line_number: The line where the opcode is found
 */
void pall_err(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

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
 */
void open_error(char *file)
{
	dprintf(2, "Error: Can't open file %s\n", file);
	exit(EXIT_FAILURE);
}
