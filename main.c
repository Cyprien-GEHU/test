#include "shell.h"

/**
 *
 *
 *
 */

int main(int av, char **arc)
{
	char *be, *splity;
	size_t n;
	int test;
	av = 0;

	printf("$ ");
	test = getline(&be, &n, stdin);
	if (test == -1)
	{
		printf("error");
		return(0);
	}

	be[strcspn(be, "\n")] = 0;
	splity = strtok(be, " ");

	while (splity)
	{
		arc[av++] = splity;
		splity = strtok(NULL, " ");
	}

	if (execve("/bin/ls", arc, NULL) == -1)
	{
		perror("Error executing command");
		free(be);
		return (1);
	}

	return(0);	
}
