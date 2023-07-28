#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* for read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* for command chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* for convert_number() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;


/**
* struct liststr - singly linked list
* @num: the number field
* @str: a string
* @next: points to the next node
*/
typedef struct liststr
{
int num;
char *str;
struct liststr *next;
} list_t;

/**
* struct passinfo - contains pseudo-arg
* allowing uniform prototype
* @arg: getline string arguments
* @argv: argument vector
* @path: string path for current cmd
* @argc: argument count
* @line_count: error count
* @err_num: error code
* @linecount_flag: count line of input
* @fname: program filename
* @env: linked copy of env
* @environ: modified copy of env
* @history: history node
* @alias: alias node
* @env_changed: cd env
* @status: return status
* @cmd_buf: pointer address to cmd_buf
* @cmd_buf_type: command type
* @readfd: fd to read line input
* @histcount: history count
*/
typedef struct passinfo
{
char *arg;
char **argv;
char *path;
int argc;
unsigned int line_count;
int err_num;
int linecount_flag;
char *fname;
list_t *env;
list_t *history;
list_t *alias;
char **environ;
int env_changed;
int status;

char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
int cmd_buf_type; /* CMD_type ||, &&, ; */
int readfd;
int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
0, 0, 0}

/**
* struct builtin - contains builtin str
* @type: cmd type builtin
* @func: function
*/
typedef struct builtin
{
char *type;
int (*func)(info_t *);
} builtin_table;


/* toem_shloop.c */
int hsh(info_t *, char **);
int builtincmd(info_t *);
void cmdpath(info_t *);
void forkcmd(info_t *);

/* toem_parser.c */
int cmdexec(info_t *, char *);
char *charsduplicity(char *, int, int);
char *findcmd(info_t *, char *, char *);

/* loophsh.c */
int loophsh(char **);

/* toem_errors.c */
void input(char *);
int putchstder(char);
int fd(char c, int fd);
int inputfd(char *str, int fd);

/* toem_string.c */
int strlength(char *);
int strcmplex(char *, char *);
char *haystkcheck(const char *, const char *);
char *concstr(char *, char *);

/* toem_string1.c */
char *copystr(char *, char *);
char *strduplicity(const char *);
void diplyinput(char *);
int putchar(char);

/* toem_exits.c */
char *cpystr(char *, char *, int);
char *catstr(char *, char *, int);
char *strloc(char *, char);

/* toem_tokenizer.c */
char **wordstr(char *, char *);
char **wordstr2(char *, char);

/* toem_realloc.c */
char *setmemory(char *, char, unsigned int);
void freestr(char **);
void *memrealloc(void *, unsigned int, unsigned int);

/* toem_memory.c */
int b(void **);

/* toem_atoi.c */
int woke(info_t *);
int delmt(char, char *);
int abchar(int);
int convert(char *);

/* toem_errors1.c */
int atoi(char *);
void errormsg(info_t *, char *);
int decprint(int, int);
char *numconvrt(long int, int, int);
void rmcomms(char *);

/* toem_builtin.c */
int exit(info_t *);
int cddir(info_t *);
int cdirprocss(info_t *);

/* toem_builtin1.c */
int hstry(info_t *);
int alias(info_t *);

/*toem_getline.c */
ssize_t getinput(info_t *);
int getlineinpt(info_t *, char **, size_t *);
void blocker(int);

/* toem_getinfo.c */
void initinfo(info_t *);
void setinfo(info_t *, char **);
void freeinfo(info_t *, int);

/* toem_environ.c */
char *getenv(info_t *, const char *);
int env(info_t *);
int setenv(info_t *);
int unsetenv(info_t *);
int envlist(info_t *);

/* toem_getenv.c */
char **getenv(info_t *);
int unsetenv(info_t *, char *);
int setenv(info_t *, char *, char *);

/* toem_history.c */
char *getfilehist(info_t *info);
int historyrw(info_t *info);
int historyrd(info_t *info);
int histrylist(info_t *info, char *buf, int linecount);
int historynum(info_t *info);

/* toem_lists.c */
list_t *addnode(list_t **, const char *, int);
list_t *endnode(list_t **, const char *, int);
size_t linkdlist(const list_t *);
int nodedel(list_t **, unsigned int);
void listfree(list_t **);

/* toem_lists1.c */
size_t listlength(const list_t *);
char **liststrng(list_t *);
size_t listdisplay(const list_t *);
list_t *nodebegins(list_t *, char *, char);
ssize_t nodeindx(list_t *, list_t *);

/* toem_vars.c */
int delchainchar(info_t *, char *, size_t *);
void checker(info_t *, char *, size_t *, size_t, size_t);
int aliasreplacer(info_t *);
int varreplacer(info_t *);
int strreplacer(char **, char *);

#endif
