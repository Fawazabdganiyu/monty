#include "monty.h"

/**
 * reduce_blank - reduces excess string spaces
 * @s: The string to check for space character
 *
 * Return: A pointer to the non space character
 */
const char *reduce_blank(const char *s)
{
	char space = ' ';

	if (*s == space)
	{
		while (1)
		{
			if (*s != space)
			{
				break;
			}
			s++;
		}

		return (s);
	}

	return (s);
}
