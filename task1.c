#include "shell.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

/**
* main - main function
*
* return: always 0
*/

int main(void)
{
char command[MAX_COMMAND_LENGTH];

while (1)
{
printf("shell> ");

if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
{
printf("\n");
break;
}

command[strcspn(command, "\n")] = '\0';
strtrim(command);

if (strcmp(command, "exit") == 0)
{
break;
}

pid_t pid = fork();

if (pid < 0)
{
perror("fork");
exit(EXIT_FAILURE);
}
else
if (pid == 0)
{
if (execlp(command, command, NULL) == -1)
{
printf("Command not found: %s\n", command);
exit(EXIT_FAILURE);
}
}
else
{
wait(NULL);
}
}

return (0);
}
