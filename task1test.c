#include "shell.h"

/**
* diplayPrompt - diplayed prompt
* executeCommand - execution of demand
* @command: the user command
* main - main
* execute_command - execution
* Return: Always return 0
*/

void displayPrompt()
{
printf("cisfun$ ");
}

void executeCommand(char* command)
{
/* Adding code to execute the command*/
printf("Executing command: %s\n", command);
}

int main()
{
char command[MAX_COMMAND_LENGTH];

while (1)
{
displayPrompt();

if (fgets(command, sizeof(command), stdin) == NULL)
{
printf("Error reading command\n");
continue;
}

/* Removing trailing newline character */
command[strcspn(command, "\n")] = '\0';

executeCommand(command);
}

return (0);
}


void executeCommand(char* command)
{
/* Create a child process */
pid_t pid = fork();

if (pid < 0)
{
/* Fork failed */
perror("Fork failed");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
/* Child process */
/* Execute the command using execlp */
execlp(command, command, NULL);

/* If execlp returns, it means the command execution failed */
perror("Command execution failed");
exit(EXIT_FAILURE);
}
else
{
/* Parent process */
/* Wait for the child process to complete */
wait(NULL);
}
}

int main()
{
char command[MAX_COMMAND_LENGTH];

while (1)
{
/* Prompt the user for a command */
printf("Enter a command: ");
scanf("%s", command);

/* Check if the user wants to exit */
if (strcmp(command, "exit") == 0)
{
break;
}

/* Execute the command */
executeCommand(command);
}

return (0);
}

void execute_command(char *command)
{
/* Tokenize the command into arguments */
char *arguments[MAX_ARGUMENTS];
char *token = strtok(command, " ");
int arg_count = 0;

while (token != NULL && arg_count < MAX_ARGUMENTS)
{
arguments[arg_count] = token;
token = strtok(NULL, " ");
arg_count++;
}
arguments[arg_count] = NULL;

/* Fork a child process */
pid_t pid = fork();

if (pid < 0)
{
perror("Fork failed");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
/* Child process */
execvp(arguments[0], arguments);

/* If execvp returns, an error occurred */
perror("Command execution failed");
exit(EXIT_FAILURE);
}
else
{
/* Parent process */
int status;
waitpid(pid, &status, 0);

if (WIFEXITED(status))
{
int exit_status = WEXITSTATUS(status);

if (exit_status != 0)
{
printf("Command exited with status %d\n", exit_status);
}
}
else if (WIFSIGNALED(status))
{
int signal_number = WTERMSIG(status);
printf("Command terminated with signal %d\n", signal_number);
}
}
}

int main()
{
char command[MAX_COMMAND_LENGTH];

while (1)
{
printf("Enter a command: ");

if (fgets(command, sizeof(command), stdin) == NULL)
{
/* End of file condition (Ctrl+D) */
printf("\n");
break;
}

/* Remove newline character from the command */
command[strcspn(command, "\n")] = '\0';

execute_command(command);
}

return (0);
}
