#include "shell.h"

/**
* setmemory - fills memory with a constant byte
* @s: memory pointer
* @b: filling bits to *s
* @n: amount of bits
* Return: a pointer to memory
*/

char *setmemory(char *s, char b, unsigned int n)
{
unsigned int i;

for (i = 0; i < n; i++)
s[i] = b;
return (s);
}

/**
* freestr - frees str
* @pp: string of strings
*/

void freestr(char **pp)
{
char **a = pp;

if (!pp)
return;
while (*pp)
free(*pp++);
free(a);
}

/**
* memrealloc - memory block reallocatn
* @ptr: pointer to prev malloc'ated
* @old_size: size of prev bits
* @new_size: size of new bits
* Return: pointer
*/
void *memrealloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *p;

if (!ptr)
return (malloc(new_size));
if (!new_size)
return (free(ptr), NULL);
if (new_size == old_size)
return (ptr);

p = malloc(new_size);
if (!p)
return (NULL);

old_size = old_size < new_size ? old_size : new_size;
while (old_size--)
p[old_size] = ((char *)ptr)[old_size];
free(ptr);
return (p);
}
