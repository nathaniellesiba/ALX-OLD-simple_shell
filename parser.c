#include "shell.h"

/**
* cmdexec - determines exec cmd file
* @info: struct arguments
* @path: to the file
* Return: 1 if true, 0 otherwise
*/

int cmdexec(info_t *info, char *path)
{
struct stat st;

(void)info;
if (!path || stat(path, &st))
return (0);

if (st.st_mode & S_IFREG)
{
return (1);
}
return (0);
}

/**
* charsduplicity - duplicates char
* @pathstr: PATH str
* @start: index
* @stop: index
*
* Return: buffer pointer
*/
char *charsduplicity(char *pathstr, int start, int stop)
{
static char buf[1024];
int i = 0, k = 0;

for (k = 0, i = start; i < stop; i++)
if (pathstr[i] != ':')
buf[k++] = pathstr[i];
buf[k] = 0;
return (buf);
}

/**
* findcmd - finds cmd in PATH str
* @info: struct arguments
* @pathstr: PATH str
* @cmd: command argument
* Return: path of cmd
*/
char *findcmd(info_t *info, char *pathstr, char *cmd)
{
int i = 0, curr_pos = 0;
char *path;

if (!pathstr)
return (NULL);
if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
{
if (is_cmd(info, cmd))
return (cmd);
}
while (1)
{
if (!pathstr[i] || pathstr[i] == ':')
{
path = dup_chars(pathstr, curr_pos, i);
if (!*path)
_strcat(path, cmd);
else
{
_strcat(path, "/");
_strcat(path, cmd);
}
if (is_cmd(info, path))
return (path);
if (!pathstr[i])
break;
curr_pos = i;
}
i++;
}
return (NULL);
}
