#include "shell.h"

#define MAX_COMMAND_LENGTH 100

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
        
        command[strcspn(command, "\n")] = '\0';  // Remove trailing newline
        
        if (strcmp(command, "exit") == 0) {
            // Exit the shell if the user types "exit"
            break;
        }
        
        pid_t pid = fork();
        
        if (pid < 0) {
            // Handle fork error
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Child process
            if (execlp(command, command, NULL) == -1) {
                // Handle executable not found error
                printf("Command not found: %s\n", command);
                exit(EXIT_FAILURE);
            }
        } else {
            // Parent process
            wait(NULL);
        }
    }
    
    return 0;
}
