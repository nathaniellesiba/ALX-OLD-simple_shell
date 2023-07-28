#include "shell.h"

/**
* strlength - returns str length
* strcmplex- strangs lexicogarphc comp
* @s: string arguments
* @s1: strang 1 arguments
* @s2: strang 2 arguments
* Return: always 0 on success
*/

int strlength(char *s)
{
int i = 0;

if (!s)
return (0);

while (*s++)
i++;
return (i);
}


int strcmplex(char *s1, char *s2)
{
while (*s1 && *s2)
{
if (*s1 != *s2)
return (*s1 - *s2);
s1++;
s2++;
}
if (*s1 == *s2)
return (0);
else
return (*s1 < *s2 ? -1 : 1);
}

/**
* haystkcheck - haystack needle check
* @haystack: string to search
* @needle: substring to find
* Return: NULL or address
*/

char *haystkcheck(const char *haystack, const char *needle)
{
while (*needle)
if (*needle++ != *haystack++)
return (NULL);
return ((char *)haystack);
}

/**
* concstr - concatenates two strings
* @dest: buffer destination
* @src: buffer source
* Return: pointer to destination
*/

char *concstr(char *dest, char *src)
{
char *ret = dest;

while (*dest)
dest++;
while (*src)
*dest++ = *src++;
*dest = *src;
return (ret);
}
