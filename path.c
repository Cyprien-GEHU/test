#include "shell.h"

/**
 * _getenv -  we search the env with the name of the variable global
 * @name : the name of variable global
 * @environ : the environ in the shell
 *
 * Return: the env we found with
 */

char *_getenv(const char *name, char **environ)
{
	int len, i;
	char *env;

	len = strlen(name);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], name, len) == 0)
		{
			env = environ[i] + len + 1;
			return (env);
		}
	}

return (NULL);
}

/**
 * get_path - we search the path with the command
 * @command : the command we send
 *
 * Return: the path with the command
 */

char *get_path(char *command)
{
	char *path, *token, *cp_path, *new_path;
	struct stat st;
	size_t len;

	path = _getenv("PATH", environ);

	if (access(command, X_OK) == 0)
		return (strdup(command));

	cp_path = strdup(path);
	if (!cp_path)
	{
		printf("error strdup");
		return (NULL);
	}

	token = strtok(cp_path, ":");
	while (token != NULL)
	{
		len = strlen(token) + strlen(command) + 2;
		new_path = malloc(sizeof(char) * len);

		if (!new_path)
			break;

		sprintf(new_path, "%s/%s", token, command);
		if (stat(new_path, &st) == 0)
		{
			free(cp_path);
			return (new_path);
		}

		free(new_path);
		token = strtok(NULL, ":");
	}
	free(token);
	free(cp_path);
	return (NULL);
}
