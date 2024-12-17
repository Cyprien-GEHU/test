#include "shell.h"

/**
 *
 *
 *
 */

int main (void)
{
	char *be, *splity;
	size_t n;
	int test;

	printf("$ ");
	test = getline(&be, &n, stdin);
	if (test == -1)
	{
		printf("error");
		return(0);
	}
	splity = strtok(be, " ");

	while (splity)
	{
		printf("%s\n", splity);
		splity = strtok(NULL, " ");
	}

	return(0);
}
