#include "monty.h"

int _isdigit(char *integer);
void push(int integer);
int execute(char **instruct, unsigned int line_number,
		char *buf, char **instructions);

/**
 * _isdigit - checks if a charater pointer is an integer
 * @integer: The integer to be checked
 *
 * Return: Non-zero if its a digit, 0 if not
 */
int _isdigit(char *integer)
{
	int i;

	for (i = 0; integer[i]; i++)
	{
		if (isdigit(integer[i]) == 0)
			return (0);
	}

	return (1);
}

/**
 * push - pushs an integer to stack list
 * @integer: An integer to be pushed
 */
void push(int integer)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (new == NULL)
		malloc_failed();

	new->n = integer;
	new->prev = NULL;
	new->next = stack;
	if (stack != NULL)
		stack->prev = new;
	stack = new;
}

/**
 * executes - interprets the opcode accordingly
 * @instruct: A pointer to an array of opcode and/or its integer
 * @line_number: The line number where the opcode is found
 * @buf: The buffer used for reading the file
 * @instructions: A pointer to an array that consist the opcodes line by line
 *
 * Return: 0 on success, non-zero on failure
 */
int execute(char **instruct, unsigned int line_number,
		char *buf, char **instructions)
{
	if (strcmp(instruct[0], "push") == 0)
	{
		if (!instruct[1] || _isdigit(instruct[1]) == 0)
		{
			dprintf(2, "L%u: usage: push integer\n", line_number);

			free_list();
			_free(instruct);
			_free(instructions);
			free(buf);
			exit(EXIT_FAILURE);
		}
		else
			push(atoi(instruct[1]));
		return (0);
	}
	if (strcmp(instruct[0], "pall") == 0)
	{
		pall();
		return (0);
	}

	return (-1);
}
