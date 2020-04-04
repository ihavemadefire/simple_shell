#include "holberton.h"
/**
 * printerror - prints errors
 * @args: arguments from command line
 *
 * Return: void
 */
void printerror(char **args)
{
	int i = 0;

	while (args[i])
	{
		printf("%s: ", args[i]);
		i++;
	}
	printf("No such file or directory\n");
}
