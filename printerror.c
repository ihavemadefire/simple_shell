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
	char *buff;

	if (args[0])
	{
		if (isat == 1)
		{
			while (args[i])
			{
				_ptstr(args[i]);
				write(STDOUT_FILENO, "\n", 1);
				i++;
			}
			buff = "No such file or directory\n";
			_ptstr(buff);
		}
		else
		{
			_ptstr(argv[0]);
			buff = ": 1: ";
			_ptstr(buff);
			while (args[i])
			{
				_ptstr(args[i]);
				buff = ": ";
				_ptstr(buff);
				i++;
			}
			buff = "not found\n";
			_ptstr(buff);
		}
	}
}
