#include "monty.h"

/**
 * final_clean - frees the remaining memories and closes file
 * @stack: A pointer to the address of the top of the stack list
 * @buf: A buffer used to read the file
 * @fd: A file descriptor of a opened file
 */
void final_clean(stack_t **stack, char *buf, int fd)
{
	free_list(stack);
	free(buf);
	close(fd);
}

