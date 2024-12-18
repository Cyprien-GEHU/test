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
int main(int ac, char **env)
{
	char *path;
	char *split;

	(void)ac;
	(void)env;
	path = _getenv("PATH", environ);

	printf("%s\n", path);

	split = strtok(path, ":");

	while (split)
	{

		printf("%s\n", split);
		split = strtok(NULL, ":");
	}
	
    return (0);
}
