#include "shell.h"

/**
 * _string - split the input and create a array with argument
 *
 * @input : the input
 *
 * Return: the array with argument
 */

char **_string(char *input)
{
	char **arg = malloc(sizeof(char *) * 1024);
	char *token;
	size_t x = 0, z = 0;

	if (!arg)
		return (NULL);

	token = strtok(input, " \n\t");

	if (!token)
	{
		free(arg);
		return (NULL);
	}

	while (token)
	{
		arg[x] = strdup(token);

		if (!arg[x])
		{
			for (; z < x; z++)
				free(arg[x]);
			free(arg);
			return (NULL);
		}
		x++;
		token = strtok(NULL, " \n\t");
	}
	free(token);
	arg[x] = NULL;
	return (arg);
}
