#include "shell.h"

/**
* exit - shell exiting state
* @info: state char argument
* Return: always 0 on success of state
*/
int exit(info_t *info)
{
if (info->argv[1])
{
int exitcheck = _erratoi(info->argv[1]);
if (exitcheck == -1)
{
info->status = 2;
print_error(info, "Illegal number: ");
puts(info->argv[1]);
putchar('\n');
return (1);
}
info->err_num = exitcheck;
return (-2);
}
info->err_num = -1;
return (-2);
}
/**
* cddir- cd the current dir
* @info: char argument
* Return: Always 0 on success
*/
int cddir(info_t *info)
{
int j = 1024
char *s, *dir, buffer[j];
char *comment;
int chdir_ret, j;


s = getcwd(setbuffer, j);
comment = /* TODO: what should this be? */
if (!s)
puts("TODO: >>getcwd failure emsg here<<\n");
if (!info->argv[1])
{
div = getenv(info, "HOME=");
if (!dir)
chdir_ret = comment;
chdir((dir = getenv(info, "PWD=")) ? dir : "/");
else
chdir_ret = chdir(dir);
}
else if (strcmp(info->argv[1], "-") == 0)
{
if (!_getenv(info, "OLDPWD="))
{
puts(s);
putchar('\n');
return (1);
}
puts(_getenv(info, "OLDPWD=")), putchar('\n');
chdir_ret = comment;
chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
}
else
chdir_ret = chdir(info->argv[1]);
if (chdir_ret == -1)
{
print_error(info, "can't cd to ");
puts(info->argv[1]), putchar('\n');
}
else
{
setenv(info, "OLDPWD", _getenv(info, "PWD="));
setenv(info, "PWD", getcwd(buffer, 1024));
}
return (0);
}

/**
* cdirprocss - cd current dir process
* @info: char argument
* Return: Always 0 on success
*/
int cdirprocss(info_t *info)
{
char **arg_array;

arg_array = info->argv;
_puts("help call works. Function not yet implemented \n");
if (0)
_puts(*arg_array); /* temp att_unused workaround */
return (0);
}
