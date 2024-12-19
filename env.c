#include "shell.h"

/**
 *
 *
 *
 */

char *_getenv(const char *name, char **environ)
{
	int len, i;
	char *env;

	len = strlen(name);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], name, len ) == 0)
		{
		        env = environ[i] + len + 1;
			return (env);
		}
	}

return (NULL);
}

/**
 * main - prints the environment
 *
 * Return: Always 0.
 */
char *get_path(char *command)
{
	char *path, *split, *cp_path;
	char new_path[1024];
	struct stat st;
	path = _getenv("PATH", environ);

	printf("%s\n", command);

	cp_path = strdup(path);

	if (!cp_path)
	{
		printf("error strdup");
		return(NULL);
	}

	split = strtok(cp_path, ":");

	while (split != NULL)
	{
		snprintf(new_path, sizeof(new_path), "%s/%s", split, command);
		if (stat(new_path, &st) == 0 && (st.st_mode & S_IXUSR))
		{
			printf("%s\n", new_path);
			free(cp_path);
			return(command);
		}
		split = strtok(NULL, ":");
	}
	free(cp_path);	
    return (NULL);
}
