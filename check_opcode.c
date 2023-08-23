#include "monty.h"

/***/
void (*check_opcode(char **instruct, unsigned int line_number))(stack_t **stack, unsigned int line_number)
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
			if (execute(instruct, line_number) == -1)
				return (codes[i].f);
		}
	}

	return (NULL);
}
