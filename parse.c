#include "monty.h"

/**
 * parse - parses the instructions given as opcodes
 * @instructions: A charcter pointer to the opcodes line by line
 * @stack: A pointer to the top of the stack list pointer
 * @instruct: A pointer to an array of opcode and/or its integer
 * @buf: The buffer used for reading the file
 * @line_number: The line number where an instruction occurs
 */
void parse(char *instructions, stack_t **stack, char **instruct,
		char *buf, unsigned int line_number)
{
	void (*func)(stack_t **stack, unsigned int line_number);

	if (instructions[0] == '#' || instructions[0] == '\0')
	{
		free(instructions);
		return;
	}
	instruct = split_string(instructions, " \t");
	func = check_opcode(stack, instruct, line_number, buf, instructions);
	if (func != NULL)
		func(stack, line_number);
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, instruct[0]);
		clean_up(stack, instruct, instructions, buf);
	}
	_free(instruct);

	free(instructions);
}
