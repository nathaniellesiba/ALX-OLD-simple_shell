#include "shell.h"

/**
* b - frees pointer
* @ptr: pointer address
* Return: always 1 if freed
*/

int b(void **ptr)
{
if (ptr && *ptr)
{
free(*ptr);
*ptr = NULL;
return (1);
}
return (0);
}
