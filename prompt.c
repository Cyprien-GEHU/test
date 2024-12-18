#include "shell.h"

/**
 *
 *
 *
 */

char *input_read(void)
{
	char *be;
	size_t n;
	int test;

	printf("$ ");
	test = getline(&be, &n, stdin);
	if (test == -1)
	{
		printf("error");
		free(be);
		return(NULL);
	}

	return(be);
}
