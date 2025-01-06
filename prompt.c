#include "shell.h"

/**
 * input_read - we write the command 
 *
 * Return: the command written
 */

char *input_read(void)
{
	char *command;
	size_t n;
	int line;

	printf("$ ");
	line = getline(&command, &n, stdin);
	if (line == -1)
	{
		printf("error");
		free(command);
		return(NULL);
	}

	return(command);
}
