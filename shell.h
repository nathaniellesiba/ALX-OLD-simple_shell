#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <stdbool.h>
#include <ctype.h>


#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10


int betty(int num1, int add1);
void prompt(char **av, char **env);
int main(int ac, char **av, char **env);
int exit(info_t *info);
int main(int ac, char **av);
void execute_command(char* command);


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


/*interactive shell*/
int interactive(info_t *info);
bool is_delim(char c, char *delim);
int _isalpha(int c);
int conv(const char *s);

/*builtin_cddir*/
int myexit(info_t *info);
int _mycd(info_t *info);
int _myhelp(info_t *info);

/*builtin_cddir1*/
int _myhistory(info_t *info);
int unset_alias(info_t *info, char *str);
int set_alias(info_t *info, char *str);
void print_alias(list_t *node);
int _myalias(info_t *info);


/*environment*/
int printEnv(info_t *info);
char *_getenv(info_t *info, const char *name);
int _mysetenv(info_t *info);
int my_unsetenv(info_t *info);
int populate_env_list(info_t *info);




#endif
