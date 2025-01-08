#include "shell.h"

/**
 * input_read - we write the command
 *
 * Return: the command written
 */

char *input_read(void)
{
	char *command = NULL;
	size_t n = 0;
	int line;

	line = getline(&command, &n, stdin);

	if (line == -1)
	{
		free(command);
		return (NULL);
	}

	return (command);
}
