# include "shell.h"

/**
* interactive - awake function
* info - interactive state info
* return: results of statu
*/

int interactive(info_t *info)
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
* is_delim - function checks char
* if char is delimiter compared delim
* @c: char to be checked
* @delim: given string of delimiters.
* bool: true if char is delim
* false if otherwise
* Return: always bool
*/

bool is_delim(char c, char *delim)
{


while (*delim)
{
if (*delim++ == c)
{
return (true);
}
}

return (false);
}


/**
* _isalpha - checks alphabetic char.
* @c: the character
* Return: 1 if char or 0 if not
*/

int _isalpha(int c)
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
* conv - convert str to int
* @s: string to convert
* main - the converted num
* Return: always 0 on success
*/

int conv(const char *s)
{
int sign = 1;
int result = 0;

/* Check for negative sign*/

if (*s == '-')
{
sign = -1;
s++;
}

/**
* Iterate through each character
* Check if char is a digit
* if not break loop
*/
while (*s != '\0')
{

if (*s >= '0' && *s <= '9')
{
result = result * 10 + (*s - '0');
}
else
{

break;
}
s++;
}

return sign * result;
}

int main(void)
{
char *str = "12345";
int num = atoi(str);
printf("Converted number: %d\n", num);
return (0);
}
