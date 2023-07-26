#include "shell.h"

/**
* _eputs - string line
* struct - declaration
* _putchar - unsigned char
* _puts - relationships
* _eputchar - char
* _getenv - get environment
* find_command_in_path - path
* _strcmp - string command
* print_error - error displayed
* _mycd - change dir
* @str: stand error
* @c: print
* @info: information
* @key: key length
* @command: input
* @s1: string command 1
* @s2: string command 2
* @msg: message
* retunr: always 0 on success
*/


typedef struct
{
char **argv;
}
info_t;

void _puts(char *str)
{
printf("%s", str);
}

void _putchar(char c)
{
printf("%c", c);
}

void _eputs(char *str)
{
fprintf(stderr, "%s", str);
}

void _eputchar(char c)
{
fprintf(stderr, "%c", c);
}

char *_getenv(info_t *info, char *key)
{
extern char **environ;
int key_length = strlen(key);
int i;

for (i = 0; environ[i] != NULL; i++)
{
if (strncmp(environ[i], key, key_length) == 0)
{
return environ[i] + key_length;
}
}

return (NULL);
}

char *find_command_in_path(char *command)
{
char *path = _getenv(NULL, "PATH=");
char *dir;
char *full_path;
int command_length = strlen(command);

if (!path)
{
return (NULL);
}

dir = strtok(path, ":");

while (dir != NULL)
{
full_path = malloc(strlen(dir) + command_length + 2);
sprintf(full_path, "%s/%s", dir, command);

if (access(full_path, X_OK) == 0)
{
return (full_path);
}

free(full_path);
dir = strtok(NULL, ":");
}

return NULL;
}

int _strcmp(char *s1, char *s2)
{
return strcmp(s1, s2);
}

void print_error(info_t *info, char *msg)
{
_eputs(msg);
}

int _mycd(info_t *info)
{
char *s, *dir, buffer[1024];
int chdir_ret;

s = getcwd(buffer, 1024);
if (!s)
{
_puts("TODO: >>getcwd failure emsg here<<\n");
}
if (!info->argv[1])
{
dir = _getenv(info, "HOME=");
if (!dir)
{
chdir_ret = chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
}
else
{
chdir_ret = chdir(dir);
}
}
else
if (_strcmp(info->argv[1], "-") == 0)
{
if (!_getenv(info, "OLDPWD="))
{
_puts(s);
_putchar('\n');
return (1);
}
_puts(_getenv(info, "OLDPWD="));
_putchar('\n');
chdir_ret = chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
}
else
{
chdir_ret = chdir(info->argv[1]);
}
if (chdir_ret == -1)
{
print_error(info, "can't cd to ");
_eputs(info->argv[1]);
_eputchar('\n');
}
else
{
_setenv(info, "OLDPWD", _getenv(info, "PWD="));
_setenv(info, "PWD", getcwd(buffer, 1024));
}
return (0);
}
