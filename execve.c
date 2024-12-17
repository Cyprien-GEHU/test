#include "shell.h"

/**
 *
 *
 *
 */

int main(int av, char **ar)
{
	int e = 1;

	while (e == 1)
	{
		if (av < 1)
		{
			printf("error");
			return (-1);
		}

		char *command;

		command = "/bin/ls";

		if (execve(command, ar, NULL) == -1)
    		{
        		perror("Error:");
    		}
	}
	return (0);
}
