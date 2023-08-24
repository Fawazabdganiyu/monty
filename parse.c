#include "monty.h"

/**
 * parse - parses the instructions given as opcodes
 * @instructions: A pointer to an array that consist the opcodes line by line
 * @stack: A pointer to the top of the stack list pointer
 * @instruct: A pointer to an array of opcode and/or its integer
 * @buf: The buffer used for reading the file
 */
void parse(char **instructions, stack_t **stack, char **instruct, char *buf)
{
	unsigned int i;
	void (*func)(stack_t **stack, unsigned int line_number);

	for (i = 0; instructions[i]; i++)
	{
		if (instructions[i][0] == '#')
			continue;
		instruct = split_string(instructions[i], " ");
		func = check_opcode(stack, instruct, i + 1, buf, instructions);
		if (func != NULL)
			func(stack, i + 1);
		else
		{
			dprintf(2, "L%u: unknown instruction %s\n", i + 1, instruct[0]);
			clean_up(stack, instruct, instructions, buf);
		}
		_free(instruct);
	}
	_free(instructions);
}
