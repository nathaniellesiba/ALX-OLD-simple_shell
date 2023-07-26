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
void execute_command(char* command);
int main(void);


/*builtin*/
int _mycd(info_t *info);
void print_error(info_t *info, char *msg);
int _strcmp(char *s1, char *s2);
char *find_command_in_path(char *command);
char *_getenv(info_t *info, char *key);
void _eputchar(char c);
void _eputs(char *str);
void _putchar(char c);
void _puts(char *str);



#endif
