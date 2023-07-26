#include "shell.h"
#include <unistd.h>

#define MAX_COMMAND 100

/**
* main: executing exit command
* return: always 0
*/
int main(void)
{
char command[MAX_COMMAND];
while (1)
{
printf("Shell> ");
fgets(command, MAX_COMMAND, stdin);
command[strcspn(command, "\n")] = '\0';
if (strcmp(command, "exit") == 0)
{
printf("Exiting the shell...\n");
break;
}
system(command);
}

return (0);
}
