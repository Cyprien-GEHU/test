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
	char *path, *split, *cp_path, *new_path;
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

	split = strtok(cp_path, ":");

	while (split != NULL)
	{
		len = strlen(split) + strlen(command) + 2;
		new_path = malloc(sizeof(char) * len);
		sprintf(new_path, "%s/%s", split, command);

		if (stat(new_path, &st) == 0)
		{
			free(cp_path);
			return (strdup(new_path));
		}
		free(new_path);
		split = strtok(NULL, ":");
	}
	free(cp_path);
	return (NULL);
}
