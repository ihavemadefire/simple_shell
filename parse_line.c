#include "holberton.h"
/**
 * read_parse_line - prints line, read and delete '\n', parse line
 * @args: will contain all words
 * @line: will get line from command line
 *
 * Return: int of fail or success
 */
int read_parse_line(char *args[], char line[])
{
	printline();
	read_line(line);
	process_line(args, line);
	return (1);
}

/**
 * printline - prints line to command line
 *
 * Return: void
 */
void printline(void)
{
	write(1, "#almosthere$ ", 13);
}

/**
 * read_line - getline from stdin
 * @line: after execution will contain args
 *
 * Return: void
 */
void read_line(char line[])
{
	ssize_t ret;
	size_t size = 100;

	ret = getline(&line, &size, stdin);
	remove_endOfLine(line);
	if (strcmp(line, "exit") == 0 || ret == -1)
		exit(1);
}

/**
 * remove_endOfLine - changes ending '\n' to '\0'
 * @line: holds the args ending in '\n'
 *
 * Return: void
 */
void remove_endOfLine(char line[])
{
	int i = 0;

	while (line[i] != '\n')
		i++;
	line[i] = '\0';
}

/**
 * process_line - seperates line into words that get stored in args
 * @args: currently empty until executing process_line
 * @line: contains all args
 *
 * Return: int for success or failure
 */
int process_line(char *args[], char line[])
{
	int i = 0;

	args[i] = strtok(line, " ");
	if (args[i] == NULL)
	{
		printf("NO ARGS\n");
		return (1);
	}
	while (args[i] != NULL)
	{
		i++;
		args[i] = strtok(NULL, " ");
	}
	return (1);
}
