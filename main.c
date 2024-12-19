#include "shell.h"

/**
 *
 *
 *
 */

int main(void)
{
	char *text, *splity, *command, *full_path;
	char **arg = NULL;
	unsigned x = 0;

	text = input_read();

	splity = malloc(sizeof(char *) * 1024);
	splity = strtok(text, " ");

	while (splity)
	{
		arg[x] = splity;
		splity = strtok(NULL, " ");
		x++;
	}

	command = arg[0];
	full_path = get_path(command);
	printf("%s\n", full_path);

	return (0);
}
