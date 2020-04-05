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


void printerror(char **args);

void printline(void);

void read_line(char line[]);

int read_parse_line(char *args[], char line[]);

void remove_endOfLine(char line[]);

int process_line(char *args[], char line[]);


#endif
