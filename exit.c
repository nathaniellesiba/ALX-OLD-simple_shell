#include "shell.h"

/**
**cpystr - copy of a string
*@dest: copying destination
*@src: str source
*@n: copied char amount
*Return: concatenated str
*/
char *cpystr(char *dest, char *src, int n)
{
int i, j;
char *s = dest;

i = 0;
while (src[i] != '\0' && i < n - 1)
{
dest[i] = src[i];
i++;
}
if (i < n)
{
j = i;
while (j < n)
{
dest[j] = '\0';
j++;
}
}
return (s);
}

/**
**catstr - string concatenater
*@dest: string 1 arguments
*@src: string 2 arguments
*@n: max bit used
*Return: concatenated str
*/
char *catstr(char *dest, char *src, int n)
{
int i, j;
char *s = dest;

i = 0;
j = 0;
while (dest[i] != '\0')
i++;
while (src[j] != '\0' && j < n)
{
dest[i] = src[j];
i++;
j++;
}
if (j < n)
dest[i] = '\0';
return (s);
}

/**
**strloc - locates char str
*@s: parsed string
*@c: char arguments
*Return: pointer to memory area
*/
char *strloc(char *s, char c)
{
do {
if (*s == c)
return (s);
} while (*s++ != '\0');

return (NULL);
}
