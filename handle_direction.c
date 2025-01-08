#include "shell.h"
#include <fcntl.h>

/**
 * handle_redirection - Handles output redirection for commands.
 * @args: Array of command arguments.
 *
 * This function processes the redirection operator (>) and sets up
 * the redirection of standard output to the specified file.
 */
void handle_redirection(char **args)
{
	int i;
	int fd;

	for (i = 0; args[i] != NULL; i++)
	{
		if (strcmp(args[i], ">") == 0)
		{
			if (args[i + 1] == NULL)
			{
				fprintf(stderr, "No file specified for redirection\n");
				return;
			}
			args[i] = NULL;
			fd = open(args[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
			if (fd == -1)
			{
				perror("open");
				return;
			}
			if (dup2(fd, STDOUT_FILENO) == -1)
			{
				perror("dup2");
				close(fd);
				return;
			}
			close(fd);
			break;
		}
	}
}

