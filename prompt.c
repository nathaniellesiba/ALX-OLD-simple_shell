#include "shell.h"
#include <sys/wait.h>

#define Max_C 10

/**
* prompt - prompt to display
* @av: used argument vector
* @env: environment variable
*
*/

void prompt(char **av, char **env)
{
int MAX_C = 10;
char *string = NULL;
int i, t, status;
size_t n = 0;
ssize_t num_char;
char *argv[MAX_C];
pid_t child_pid;

while (1)
{
if (isatty(STDIN_FILENO))
printf("cisfun$ ");

num_char = getline(&string, &n, stdin);
if (num_char == -1)
{
free(string);
exit(EXIT_FAILURE);
}
i = 0;
while (string[i])
{
if (string[i] == '\n')
string[i] = 0;
i++;

}
t = 0;
argv[t] = strtok(string, " ");
while (argv[t])

t++;
argv[t] = strtok(NULL, " ");

child_pid = fork();
if (child_pid == -1)
{
free(string);
exit(EXIT_FAILURE);

}

if (child_pid == 0)
{

if (execve(argv[0], argv, env) == -1)

printf("%s: No such file\n", av[0]);
}
else
wait(&status);
}
}
