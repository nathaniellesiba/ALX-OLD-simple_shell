#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10


int betty(int num1, int add1);
void prompt(char **av, char **env);
int main(int ac, char **av, char **env);
int exit(info_t *info);
int main(int ac, char **av);


#endif
