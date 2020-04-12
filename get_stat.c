#include "holberton.h"
/**
 * get_stat - test all path to get correct one
 * @pathargs: contains path with args on end
 * @args: contains all args
 *
 * Return: pointer to correct executable path
 */
char *get_stat(char *pathargs[], char *args[])
{
	int i = 0, j;

	j = set_stat(args[0]);
	if (j > 0)
		return (args[0]);
	while (pathargs[i])
	{
		j = set_stat(pathargs[i]);
		if (j > 0)
		{
			return (pathargs[i]);
		}
		i++;
	}
	return (NULL);
}

/**
 * set_stat - test each path one at a time
 * @arguments: contains one path
 *
 * Return: 1 on success 0 on failure
 */
int set_stat(char arguments[])
{
	struct stat buf;

	stat(arguments, &buf);
	if (buf.st_dev > 0)
		return (1);
	return (0);
}
