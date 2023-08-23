#include "monty.h"

/**
 * main - Entry point of the program
 * @ac: An argument counter
 * @av: A pointer to an array of arguments passed to the program
 *
 * Return: 0 on success, non-zero otherwise
 */
int main(int ac, char **av)
{
	char *file = av[1], *buf = NULL, **instructions = NULL, **instruct = NULL;
	int nread, i, fd;
	void (*func)(stack_t **stack, unsigned int line_number);

	if (ac != 2)
		usage_error();

	fd = open(file, O_RDONLY);
	if (fd == -1)
		open_error(file);

	buf = malloc(sizeof(char) * BUF_SIZE);
	if (buf == NULL)
		malloc_failed();

	memset(buf, 0, BUF_SIZE);
	while ((nread = read(fd, buf, BUF_SIZE)) > 0)
	{
		/* Get an array of opcodes by their lines */
		instructions = split_string(buf, "\n");
		/* Split each opcode on each line into its opcode and integer if it has */
		for (i = 0; instructions[i]; i++)
		{
			instruct = split_string(instructions[i], " ");
			func = check_opcode(instruct, i + 1, buf, instructions);
			if (func != NULL)
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
