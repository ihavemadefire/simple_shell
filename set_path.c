#include "holberton.h"

/**
 * set_path - setpath for execve
 * @args: arguments given
 * @envp: env arguments given
 *
 * Return: char pointer containing path
 */
char *set_path(char **args, char **envp)
{
	char path[PATH_MAX], temp[PATH_MAX], finaltemp[PATH_MAX];
	char *pathargs[10];
	char *finalpatharg;
	int i = 0, j = 0;

	if (args[0] != NULL)
	{
		while (envp[i])
		{
			if (envp[i][0] == 'P')
			{
				while (envp[i][j])
				{
					path[j] = envp[i][j];
					j++;
				}
				break;
			}
			i++;
		}
		path[j] = '\0';
		setpath(temp, path);
		concatpath(temp, finaltemp, args);
		envstrtok(finaltemp, pathargs);
		finalpatharg = get_stat(pathargs, args);
		return (finalpatharg);
	}
	return (NULL);
}
/**
 * executepath - called from main to execute
 * @finalpatharg: contains correct path
 * @args: args given
 *
 * Return: int for success or fail
 */
int executepath(char finalpatharg[], char *args[])
{
	int i;

	i = execve(finalpatharg, args, NULL);
	if (i == -1)
		return (0);
	return (1);
}
/**
 * concatpath - combine args[0] and temp to finaltemp
 * @temp: contains full path with no command
 * @finaltemp: will contain path with command
 * @args: contain all args
 *
 * Return: void
 */
void concatpath(char temp[], char finaltemp[], char *args[])
{
	char *holder = args[0];
	int i = 0, j = 0, k = 0;

	while (temp[i])
	{
		if (temp[i] == ':')
		{
			j = 0;
			finaltemp[k] = '/';
			k++;
			while (holder[j])
			{
				finaltemp[k] = holder[j];
				j++;
				k++;
			}
		}
		finaltemp[k] = temp[i];
		k++;
		i++;
	}
	finaltemp[k] = '/';
	k++;
	j = 0;
	while (holder[j])
	{
		finaltemp[k] = holder[j];
		k++;
		j++;
	}
	finaltemp[k] = '\0';
}
/**
 * envstrtok - uses strtok to seperate final temp by ':' to create list
 * @finaltemp: contains full path
 * @pathargs: will contain full path seperated at ':'
 *
 * Return: void
 */
void envstrtok(char finaltemp[], char *pathargs[])
{
	int i = 0;

	pathargs[i] = strtok(finaltemp, ":");

	while (pathargs[i])
	{
		i++;
		pathargs[i] = strtok(NULL, ":");
	}
}
/**
 * setpath - takes PATH= out of path
 * @temp: will contain new usable path
 * @path: contains path with PATH=
 *
 * Return: void
 */
void setpath(char temp[], char path[])
{
	int i = 0, j = 0;

	while (path[i] != '/')
		i++;
	while (path[i])
	{
		temp[j] = path[i];
		i++;
		j++;
	}
	temp[j] = '\0';
}
