#include "shell.h"

/**
* myexit - If there is an exit argument
* @info: the exit argument
* Return: always 0 on success status
*/

int myexit(info_t *info)
{
if (info->argv[1])
{
int exitcheck = _erratoi(info->argv[1]);
if (exitcheck == -1)
{
info->status = 2;
print_error(info, "Illegal number: ");
_eputs(info->argv[1]);
_eputchar('\n');
return (1);
}
info->err_num = exitcheck;
return (-2);
}
info->err_num = -1;
return (-2);
}


/**
* _mycd - directory changes
* @info: potential argument
* return: 1 or correct chdir
*/

int _mycd(info_t *info)
{
char buffer[1024];
char *current_dir = getcwd(buffer, 1024);


if (!current_dir)
{
printf("TODO: >>getcwd failure emsg here<<\n");
}

if (!info->argv[1])
{
char *home_dir = _getenv(info, "HOME=");
char *dir = (home_dir != NULL) ? home_dir : _getenv(info, "PWD=");
int chdir_ret = chdir(dir);

if (!dir)
{
chdir_ret = chdir("/");
}

return chdir_ret;
}
else
if (strcmp(info->argv[1], "-") == 0)
{
char *old_pwd = _getenv(info, "OLDPWD=");

if (!old_pwd)
{
printf("%s\n", current_dir);
return 1;
}

printf("%s\n", old_pwd);
return chdir(old_pwd);
}
else
{
return chdir(info->argv[1]);
}
}

/**
* _myhelp - dir change process
* @info: argument
* return: always 0 on success
*/

int _myhelp(info_t *info)
{
char **arg_array = info->argv;
_puts("help call works. Function not yet implemented \n");

if (1 == 0)
{
_puts(*arg_array);
}
return (0);
}

