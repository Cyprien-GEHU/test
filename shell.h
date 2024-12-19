#ifndef SHELL_FILE
#define SHELL_FILE

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

char *input_read(void);
char *_getenv(const char *name, char **environ);
char *get_path(char *command);
extern char **environ;

#endif
