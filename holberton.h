#ifndef HOLBERTON_
#define HOLBERTON_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * struct buffer - holds string given size of string and current index
 * @b: string input
 * @size: len of buffer
 * @current: if needed to keep track of index
 */
typedef struct buffer
{
	char *b;
	size_t size;
	unsigned int current;
} buffer;


/**
 * struct dble - contains two integers used for malloc
 * @a: size of whole string
 * @b: number of words
 */
typedef struct dble
{
	int a;
	int b;
} dble;


dble *mallocount(buffer *buff, dble *count);

int exec(char **buff);

int _strtok(buffer *buff, dble *count);

#endif
