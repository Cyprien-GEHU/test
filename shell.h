#ifndef SHELL_FILE
#define SHELL_FILE

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

char *input_read(void);
char **_string(char *input);
int ex_build(char **args);
int execute_command(char **array);
void handle(int signal);
void prompt(void);
char *_getenv(const char *name, char **environ);
char *get_path(char *command);
void handle_redirection(char **args);
void print_environement(void);

extern char **environ;

#endif
