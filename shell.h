#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>


int betty(int num1, int add1);
void prompt (char **av, char **env);
int main(int ac, char **av, char **env);


#endif
