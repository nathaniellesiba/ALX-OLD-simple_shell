#include "shell.h"

/**
* getfilehist - history of file
* @info: parameter struct arguments
* Return: allocated str
*/

char *getfilehist(info_t *info)
{
char *buf, *dir;

dir = getenv(info, "HOME=");
if (!dir)
return (NULL);
buf = malloc(sizeof(char) * (strlen(dir) + strlen(HIST_FILE) + 2));
if (!buf)
return (NULL);
buf[0] = 0;
strcpy(buf, dir);
strcat(buf, "/");
strcat(buf, HIST_FILE);
return (buf);
}

/**
* historyrw - rw file
* @info: parameter struct arguments
* Return: always 1 on success
*/

int historyrw(info_t *info)
{
ssize_t fd;
char *filename = get_history_file(info);
list_t *node = NULL;

if (!filename)
return (-1);

fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
free(filename);
if (fd == -1)
return (-1);
for (node = info->history; node; node = node->next)
{
putsfd(node->str, fd);
putfd('\n', fd);
}
putfd(BUF_FLUSH, fd);
close(fd);
return (1);
}

/**
* historyrd - reads history
* @info: parameter struct arguments
* Return: count on success
*/
int historyrd(info_t *info)
{
int i, last = 0, linecount = 0;
ssize_t fd, rdlen, fsize = 0;
struct stat st;
char *buf = NULL, *filename = get_history_file(info);

if (!filename)
return (0);

fd = open(filename, O_RDONLY);
free(filename);
if (fd == -1)
return (0);
if (!fstat(fd, &st))
fsize = st.st_size;
if (fsize < 2)
return (0);
buf = malloc(sizeof(char) * (fsize + 1));
if (!buf)
return (0);
rdlen = read(fd, buf, fsize);
buf[fsize] = 0;
if (rdlen <= 0)
return (free(buf), 0);
close(fd);
for (i = 0; i < fsize; i++)
if (buf[i] == '\n')
{
buf[i] = 0;
build_history_list(info, buf + last, linecount++);
last = i + 1;
}
if (last != i)
build_history_list(info, buf + last, linecount++);
free(buf);
info->histcount = linecount;
while (info->histcount-- >= HIST_MAX)
delete_node_at_index(&(info->history), 0);
renumber_history(info);
return (info->histcount);
}

/**
* histrylist - adds entry
* @info: char arguments
* @buf: buffer
* @linecount: history count
* Return: Always 0 on success
*/
int histrylist(info_t *info, char *buf, int linecount)
{
list_t *node = NULL;

if (info->history)
node = info->history;
add_node_end(&node, buf, linecount);

if (!info->history)
info->history = node;
return (0);
}

/**
* historynum - renumbers the history
* @info: char arguments
* Return: new history count
*/
int historynum(info_t *info)
{
list_t *node = info->history;
int i = 0;

while (node)
{
node->num = i++;
node = node->next;
}
return (info->histcount = i);
}
