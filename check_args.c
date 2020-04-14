#include "holberton.h"
/**
 * check_args - checks args for key words exit or env
 * @args: contains all args
 * @envp: conatains all env variables
 *
 * Return: int
 */
int check_args(char *args[], char *envp[])
{
	char *temp = args[0];
	char *array[] = {"exit", "env", NULL};
	int i = 0;
	int check = 1;

	if (args[0])
	{
		while (array[i])
		{
			if (_strcmp(temp, array[i]) == 0)
			{
				if (i == 0)
					check_exit(args[1]);
				if (i == 1)
					check = check_env(envp);
			}
			i++;
		}
		return (check);
	}
	else
		return (0);
}
/**
 * check_env - prints out all env variables
 * @envp: contains all env variables
 *
 * Return: int
 */
int check_env(char **envp)
{
	int i = 0, j = 0;
	char *buff;
	while (envp[i])
	{
		j = _strlen(envp[i]);
		buff = envp[i];
		write(STDOUT_FILENO, buff, j);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (0);
}
/**
 * check_exit - when exit is passed function is executed
 * @temp: contains exit number passed
 *
 * Return: void
 */
void check_exit(char *temp)
{
	int i = 0;

	if (temp)
	{
		i = _atoi(temp);
		_exit(i);
	}
	_exit(0);
}
