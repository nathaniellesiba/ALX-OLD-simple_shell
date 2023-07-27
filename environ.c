#include "shell.h"

/**
* printEnv - diplay current env
* @info: arguments
* return: always 0 on success
*/

int printEnv(info_t *info)
{
printListStr(info->env);
return 0;
}

/**
* _getenv - diplay value of env
* @info: arguments
* @name: name of env var
* return: always 0 on success
*/

char *_getenv(info_t *info, const char *name)
{
list_t *node = info->env;
char *p = NULL;

while (node != NULL && (p = starts_with(node->str, name)) == NULL)
{
node = node->next;
}

return (p);
}

/**
* _mysetenv - add new env var
* @info: arguments
* return: always 0 on success
*/

int _mysetenv(info_t *info)
{
if (info->argc != 3)
{
_eputs("Incorrect number of arguments\n");
return (1);
}

if (!_setenv(info, info->argv[1], info->argv[2]))
{
return (1);
}

return (0);
}


/**
* my_unsetenv - delete env var
* @info: arguments
* return: always 0 on success
*/

int my_unsetenv(info_t *info)
{
int i;

if (info->argc < 2)
{
_eputs("Too few arguments.\n");
return (1);
}

for (i = 1; i < info->argc; i++)
{
_unsetenv(info, info->argv[i]);
}

return (0);
}

/**
* populate_env_list - linked env list
* @info: arguments
* return: always 0 on success
*/

int populate_env_list(info_t *info)
{
list_t *node = NULL;
size_t i = 0;

while (environ[i] != NULL)
{
add_node_end(&node, environ[i], 0);
i++;
}

info->env = node;
return (0);
}
