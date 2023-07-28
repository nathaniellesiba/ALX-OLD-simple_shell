#include "shell.h"

/**
* listlength - deter length linked lst
* @h: node 1 pointer
* Return: always 0 on success
*/
size_t listlength(const list_t *h)
{
size_t i = 0;

while (h)
{
h = h->next;
i++;
}
return (i);
}

/**
* liststrng - ret array str list->str
* @head: node 1 pointer
* Return: array of strings
*/
char **liststrng(list_t *head)
{
list_t *node = head;
size_t i = list_len(head), j;
char **strs;
char *str;

if (!head || !i)
return (NULL);
strs = malloc(sizeof(char *) * (i + 1));
if (!strs)
return (NULL);
for (i = 0; node; node = node->next, i++)
{
str = malloc(_strlen(node->str) + 1);
if (!str)
{
for (j = 0; j < i; j++)
free(strs[j]);
free(strs);
return (NULL);
}

str = _strcpy(str, node->str);
strs[i] = str;
}
strs[i] = NULL;
return (strs);
}


/**
* listdisplay - display all elements
* @h: node 1 pointer
* Return: always 0 on success
*/
size_t listdisplay(const list_t *h)
{
size_t i = 0;

while (h)
{
_puts(convert_number(h->num, 10, 0));
_putchar(':');
_putchar(' ');
_puts(h->str ? h->str : "(nil)");
_puts("\n");
h = h->next;
i++;
}
return (i);
}

/**
* nodebegins - ret node prefix str
* @node: lst head pointer
* @prefix: matching str
* @c: char arguments
* Return: node or null
*/
list_t *nodebegins(list_t *node, char *prefix, char c)
{
char *p = NULL;

while (node)
{
p = starts_with(node->str, prefix);
if (p && ((c == -1) || (*p == c)))
return (node);
node = node->next;
}
return (NULL);
}

/**
* nodeindx - gets index
* @head: lst head pointer
* @node: node pointer
* Return: node or -1
*/
ssize_t nodeindx(list_t *head, list_t *node)
{
size_t i = 0;

while (head)
{
if (head == node)
return (i);
head = head->next;
i++;
}
return (-1);
}

