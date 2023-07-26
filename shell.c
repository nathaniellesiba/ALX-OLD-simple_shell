#include "shell.h"

/**
* main - main function
* @ac: argument count to allow prompt
* @av: argument vector
* @env: the environment
* Return: Always 0 on success
*/


int main(int ac, char **av, char **env)
{
int b = 2;
int t = 1;
int d = b - t;

if (ac == d)
prompt(av, env);
return (0);
}
