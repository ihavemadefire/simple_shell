#include "holberton.h"
/**
 * printerror - prints errors
 * @args: arguments from command line
 * @argv: used for command typed in outside shell
 * @times: contains amount of times shell is used
 * @isat: tells us whether we are inside or outside the shell
 *
 * Return: void
 */
void printerror(char **args, char **argv, int times, int isat)
{
	char *buff;

	if (args[0])
	{
		if (isat == 1)
			buff = create_argv(argv);
		else
			buff = (argv[0]);
		_ptstr("./");
		_ptstr(buff);
		_ptstr(": ");
		buff = intostr(times);
		_ptstr(buff);
		_ptstr(": ");
		buff = args[0];
		_ptstr(buff);
		_ptstr(": ");
		buff = "not found\n";
		_ptstr(buff);
	}
}

/**
 * intostr - converts int to string to be printed
 * @times: int converted to string
 *
 * Return: char pointer containing num
 */
char *intostr(int times)
{
	int j, l = 0, div = 1;
	int count = 0, holder, position;
	int k[] = {10, 100, 1000};
	char string[5], *ret;

	j = times;
	while (j > 0)
	{
		j = j / div;
		div *= 10;
		count++;
	}
	position = count - 2;

	while (j < count)
	{
		holder = times % k[j];
		if (j != 0)
			holder = holder / k[j - 1];
		l = 0;
		string[position] = '0';
		while (l < holder)
		{
			string[position]++;
			l++;
		}
		position--;
		j++;
	}
	string[count - 1] = '\0';
	ret = string;
	return (ret);
}

/**
 * create_argv - removes ./ from ./hsh for error print
 * @argv: contains name of file
 *
 * Return: char pointer
 */
char *create_argv(char *argv[])
{
	int i = 2, j = 0;
	char buff[20];
	char *ret;

	while (argv[0][i])
	{
		buff[j] = argv[0][i];
		j++;
		i++;
	}
	buff[j] = '\0';
	ret = buff;
	return (ret);
}
