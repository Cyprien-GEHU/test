#include "shell.h"

/**
 * handle - handle the EOF and CTRL C
 *
 * @signal : we don't use
 */

void handle(int signal)
{
	char cwd[1024];
	(void)signal;

	write(STDOUT_FILENO, "\n", 1);

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		write(STDOUT_FILENO, "$", 1);
	}
	else
		write(STDOUT_FILENO, "root", 4);
}

/**
 * prompt - the prompt of simple shell
 *
 */

void prompt(void)
{
	char cwd[1024];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$", 1);
	}
	else
		write(STDOUT_FILENO, "root", 4);
}
