include "shell.h"

/**
* woke - returns in interactive mode
* @info: struct address
* Return: interactive mode
*/
int woke(info_t *info)
{
int isInteractive = 0;

if (isatty(STDIN_FILENO))
{
if (info->readfd <= 2)
{
isInteractive = 1;
}
}

return (isInteractive);
}

/**
* delmt - delimeter char checker
* @c: char argument
* @delim: delimeter string
* Return: 1 on true, 0 on false
*/
int delmt(char c, char *delim)
{
while (*delim)
if (*delim++ == c)
return (1);
return (0);
}

/**
* abchar - alphabetic char checker
* @c: char argument
* Return: 1 on success, 0 otherwise
*/

int abchar(int c)
{

if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
{
return (1);
}
else
{
return (0);
}
}

/**
* convert - string to int convertion
* @s: string argument
* Return: output of convertion
*/

int convert(char *s)
{
int i, sign = 1, flag = 0, output;
unsigned int result = 0;

for (i = 0; s[i] != '\0' && flag != 2; i++)
{
if (s[i] == '-')
sign *= -1;

if (s[i] >= '0' && s[i] <= '9')
{
flag = 1;
result *= 10;
result += (s[i] - '0');
}
else if (flag == 1)
flag = 2;
}

if (sign == -1)
output = -result;
else
output = result;

return (output);
}
