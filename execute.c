#include "shell.h"

/**
 * print_env - print the environement
 *
 */

void print_env(void)
{
	int y;

	for (y = 0; environ[y] != NULL; y++)
	       printf("%s\n", environ[y]);	
}

/**
 * execute_command - fucntion that execute the command received
 * @array: command received in a array after split_string
 * Return: 1 on succes
 */

int execute_command(char **array)
{
	pid_t pid;
	int status;
	char *command_path;

	if (!array)
		return (1);

	if (ex_build(array))
		return (0);
	handle_redirection(array);

	command_path = get_path(array[0]);

	if (!command_path)
	{
		fprintf(stderr, "%s: command not found\n", array[0]);
		return (1);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("Error fork");
		free(command_path);
		return (1);
	}
	if (pid == 0)
	{
		if (execve(command_path, array, environ) == -1)
		{
			perror("Error execve");
			free(command_path);
			exit(1);
		}
	}
	else
		wait(&status);

	free(command_path);

return (0);
}

/**
 * ex_build - blablabla
 *
 * @args: argument
 *
 * Return: 0 or 1
 */

int ex_build(char **args)
{
	if (args == NULL || args[0] == NULL)
		return (0);

	if (strcmp(args[0], "env") == 0)
	{
		print_env();
		return (1);
	}

	if (strcmp(args[0], "exit") == 0 && args[1] != NULL)
	{
		return (1);
	}

	if (strcmp(args[0], "exit") == 0)
	{
		free(args);
		exit(0);
	}

	if (strcmp(args[0], "cd") == 0)
	{
		printf("je change de direction");
		return (1);
	}
	return (0);
}
