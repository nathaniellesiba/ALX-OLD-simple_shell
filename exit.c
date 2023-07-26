#include "shell.h"

/**
* exit - exits the shell
* @info: argument structure
* constant function prototype.
* Return: based on status
* (0) if info.argv[0] != "exit"
*/
int exit(info_t *info)
{
int t, j, i;
int res;

i = 1;
j = 2;
res = _erratoi

if (info->argv[1])
{
t = res(info->argv[i]);
if (t == -1)
{
info->status = j;
print_error(info, "Illegal number: ");
_eputs(info->argv[i]);
_eputchar('\n');
return (1);
}
info->err_num = res(info->argv[i]);
return (-2);
}
info->err_num = -1;
return (-2);
}
