#ifndef HOLBERTON_
#define HOLBERTON_

#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <limits.h>
#include <sys/stat.h>


char *intostr(int times);

char *create_argv(char *argv[]);

void _ptstr(char *s);

int _strcmp(char *s1, char *s2);

int _strlen(char *s);

int isNumericChar(char x);

int _atoi(char *s);

int check_env(char *envp[]);

void check_exit(char *temp);

int check_args(char *args[], char *envp[]);

void helper(void);

void handler(int num);

char *get_stat(char *pathargs[], char *args[]);

int set_stat(char arguments[]);

char *set_path(char **args, char **envp);

int executepath(char finalpatharg[], char *args[]);

void concatpath(char temp[], char finaltemp[], char *args[]);

void envstrtok(char finaltemp[], char *pathargs[]);

void setpath(char temp[], char path[]);

void printerror(char **args, char **av, int times, int isat);

void printline(void);

int read_line(char line[]);

int read_parse_line(char *args[], char line[], int isat);

void remove_endOfLine(char line[]);

int process_line(char *args[], char line[]);



#endif
