#include "holberton.h"
/**
 * printerror - prints errors
 * @args: arguments from command line
 * @argv: used for command typed in outside shell
 * @isat: tells whether we are in the shell or outside
 *
 * Return: void
 */
void printerror(char **args, char **argv, int isat)
{
	int i = 0;

	if (args[0])
	{
		if (isat == 1)
		{
			while (args[i])
			{
				printf("%s: ", args[i]);
				i++;
			}
			printf("No such file or directory\n");
		}
		else
		{
			printf("%s: 1: ", argv[0]);
			while (args[i])
			{
				printf("%s: ", args[i]);
				i++;
			}
			printf("not found\n");
		}
	}
}
