#include "shell.h"

/**
 * main - cree a simple shell
 *
 * Return: 0;
 */

int main(void)
{
	char *text, **arg;
	int  x;

	signal(SIGINT, handle);
	while (1)
	{
		prompt();
		text = input_read();
		if (!text)
			break;
		if (strcmp(text, "\n") == 0 || strlen(text) == 0)
		{
			free(text);
			continue;
		}
		if (text[strlen(text)] == '\n')
			text[strlen(text)] = '\0';
		if (strcmp(text, "exit") == 0)
		{
			free(text);
			exit(0);
		}
		arg = _string(text);
		if (!arg)
		{
			free(text);
			continue;
		}
		if (arg[0] != NULL)
			execute_command(arg);

		for (x = 0; arg[x] != NULL; x++)
			free(arg[x]);
		free(arg);
		free(text);
	}
	return (0);
}
