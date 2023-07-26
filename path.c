#include "shell.h"

#define MAX_CMD_LENGTH 100
#define MAX_ARGS 10

/**
* execute_command - command execution
* @command: the actual command
*
* return: always 0
*/

void execute_command(char* command);

int main(void)
{
char command[MAX_CMD_LENGTH];

while (1)
{
printf("Shell> ");
fgets(command, MAX_CMD_LENGTH, stdin);


command[strcspn(command, "\n")] = '\0';


if (strcmp(command, "exit") == 0)
{
break;
}

execute_command(command);
}

return (0);
}

void execute_command(char* command)
{
char* args[MAX_ARGS];
char* token;
int arg_count = 0;
int j, i;

j = sizeof(command_path);
i = path_token


token = strtok(command, " ");
while (token != NULL && arg_count < MAX_ARGS - 1)
{
args[arg_count] = token;
token = strtok(NULL, " ");
arg_count++;
}
args[arg_count] = NULL;


char* path = getenv("PATH");
char* i = strtok(path, ":");
char command_path[MAX_CMD_LENGTH];
int command_exists = 0;

while (i != NULL)
{
snprintf(command_path, j, "%s/%s", i, args[0]);
if (access(command_path, F_OK) == 0)
{
command_exists = 1;
break;
}
i = strtok(NULL, ":");
}


if (command_exists)
{
pid_t pid = fork();

if (pid == -1)
{
perror("fork");
exit(1);
}
else
if (pid == 0)
{

execv(command_path, args);
perror("execv");
exit(1);
}
else
{

int status;
waitpid(pid, &status, 0);
}
}
else
{
printf("Command not found: %s\n", args[0]);
}
}
