#include "monty.h"

/***/
int main(int ac, char **av)
{
	char *file = av[1], *buf, **instructions = NULL, **instruct = NULL;
	int nread, i, fd;
	void (*func)(stack_t **stack, unsigned int line_number);

	if (ac != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	if ((fd = open(file, O_RDONLY)) == -1)
	{
		dprintf(2, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}

	buf = NULL;
	buf = malloc(sizeof(char) * BUF_SIZE);
	if (buf == NULL)
		malloc_failed();

	while ((nread = read(fd, buf, BUF_SIZE)) > 0)
	{
		instructions = split_string(buf, "\n");
		/* split the words in each intructions into two */
		for (i = 0; instructions[i]; i++)
		{
			instruct = split_string(instructions[i], " ");
			if ((func = check_opcode(instruct, i, buf, instructions)) != NULL)
				func(&stack, i);

			_free(instruct);
		}
		_free(instructions);
	}

	free_list();
	free(buf);
	close(fd);
	return (0);
}
