#include "shell.h"


/**
* _myhistory - print history
* @info: the argument
* return: always 0 on success
*/

int _myhistory(info_t *info)
{
int j = info->history;
print_list(j);
return (0);
}

/**
* unset_alias - set alias to string
* @info: argument parameter
* @str: string
* return: always 0 on success
*/

int unset_alias(info_t *info, char *str)
{
char *j, sv_char;
int ret;

j = strchr(str, '=');
if (!j)
{
return (1);
}

sv_char = *j;
*j = '\0';

int node_index = get_node_index(info->alias, node_starts_with(info->alias, str, -1));
ret = delete_node_at_index(&(info->alias), node_index);

*j = sv_char;

return (ret);
}

/**
* set_alias - alias to string
* @info: argument parameter
* @str: string
* return: always 0 on success
*/

int set_alias(info_t *info, char *str)
{
char *p;

p = strchr(str, '=');
if (!p)
return (1);

if (!*(++p))
return unset_alias(info, str);

unset_alias(info, str);
return (add_node_end(&info->alias, str, 0) == NULL);
}

/**
* print_alias - prints alias string
* @node: the alias node
*/

void print_alias(list_t *node)
{
if (node)
{
char *p = _strchr(node->str, '=');
if (p)
{
for (char *a = node->str; a <= p; a++)
{
_putchar(*a);
}
_putchar('\'');
_puts(p + 1);
_putchar('\'');
_putchar('\n');
}
}
}

/**
* _myalias - alias like builtin_cddir
* @info: arguments
*  Return: Always 0
*/

int _myalias(info_t *info)
{
int i = 0;
char *p = NULL;
list_t *node = NULL;

if (info->argc == 1)
{
/*check node exist bef prnt all alias*/
print_all_aliases(info->alias);
return (0);
}

for (i = 1; info->argv[i]; i++)
{
p = strchr(info->argv[i], '=');
if (p)
set_alias(info, info->argv[i]);
else
{
node = find_alias(info->alias, info->argv[i]);
if (node)
print_alias(node);
}
}

return (0);
}



