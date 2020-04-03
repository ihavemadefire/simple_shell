#include "holberton.h"
/**
 * exec - either execve program or prints contents
 * @tokens: malloced char **pointer to inputs
 *
 * Return: int
 */
int exec(char **buff)
{
	int i = 0;
	char *temp = buff[0];

	if (buff[0][0] == '.' && buff[0][1] == '/')
	{
		printf("IN EXCEVE\n");
		execve(temp, buff, NULL);
	}
	else
	{
		printf("NO FILE\n");
		while (buff[i])
		{
			printf("%s", buff[i]);
			i++;
		}
	}
	return(0);
}
