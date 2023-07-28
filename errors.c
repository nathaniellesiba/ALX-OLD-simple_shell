#include "shell.h"

/**
* input - display string input
* @str: printed string
* Return: Nothing
*/

void input(char *str)
{
int i = 0;

if (!str)
return;
while (str[i] != '\0')
{
_eputchar(str[i]);
i++;
}
}

/**
* putchstder - rw to stderr
* @c: char arguments
* Return: always 1 on success
*/

int putchstder(char c)
{
static int i;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(2, buf, i);
i = 0;
}
if (c != BUF_FLUSH)
buf[i++] = c;
return (1);
}

/**
* fd - rw char to given fd
* @c: char arguments
* @fd: file to rw to
*
* Return: always 1 on success
*/

int fd(char c, int fd)
{
static int i;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(fd, buf, i);
i = 0;
}
if (c != BUF_FLUSH)
buf[i++] = c;
return (1);
}

/**
* input - diplay input string
* @str: string arguments
* @fd: file to rw to
* Return: always 0 on success
*/
int inputfd(char *str, int fd)
{
int i = 0;

if (!str)
return (0);
while (*str)
{
i += _putfd(*str++, fd);
}
return (i);
}
