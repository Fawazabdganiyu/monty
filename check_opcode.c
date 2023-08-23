#include "monty.h"

/**
 * check_opcode - checks the opcodes and execute appropriately
 * @instruct: A pointer to an array of opcode and/or its integer
 * @line_number: The line number where the opcode is found
 * @buf: The buffer used for reading the file
 * @instructions: A pointer to an array that consist the opcodes line by line
 *
 * Return: A pointer to a function that returns void
 */
func check_opcode(char **instruct, unsigned int line_number, char *buf,
		char **instructions)
{
	int i;

	instruction_t codes[] = {
		{"push", push_err},
		{"pall", pall_err},
		{NULL, NULL}
	};

	for (i = 0; codes[i].opcode; i++)
	{
		if (strcmp(codes[i].opcode, instruct[0]) == 0)
		{
			if (execute(instruct, line_number, buf, instructions) == -1)
				return (codes[i].f);
		}
	}

	return (NULL);
}
