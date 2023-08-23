#include "monty.h"

/**
 * get_words - returns the number of words in a string
 * @s: The string to be tranversed
 *
 * Return: The number of words counted
 */
unsigned int get_words(char *s)
{
	unsigned int i, len = 0, spaced = 0;
	char space = ' ';

	for (i = 0; s[i]; i++)
	{
		if (s[i] == space)
		{
			if (spaced == 0)
				++len;
			spaced = 1;
			continue;
		}
		spaced = 0;
	}

	return (len + 1);
}

/***/
unsigned int get_line(char *buf)
{
	unsigned int lines = 0, i;

	for (i = 0; buf[i]; i++)
	{
		if (buf[i] == '\n')
			lines++;
	}

	return (lines);
}

/***/
char **split_string(char *buf, char *delim)
{
	char *opcode, **arr;
	unsigned int lines, i = 0;

	lines = get_line(buf);
	if (lines == 0)
		lines = get_words(buf);

	arr = malloc(sizeof(char *) * (lines + 1));
	if (arr == NULL)
		malloc_failed();

	opcode = strtok(buf, delim);
	while (opcode)
	{
		arr[i++] = strdup(opcode);
		opcode = strtok(NULL, delim);
	}
	arr[i] = NULL;

	return (arr);
}
