#include "holberton.h"
/**
 * main - simple shell
 * @argc: arg count
 * @argv: arg contents
 * @envp: environment variables
 *
 * Return: int
 */
int main(int argc, char **argv, char **envp)
{
	(void)argc, (void)argv, (void)envp;
	buffer buff = {NULL, 10, 0};
	ssize_t len_buff;
	dble count = {0, 0};
	dble *countp = &count;
	int i;

	i = 0;
	printf("#almostdone$ ");
	len_buff = getdelim(&buff.b, &buff.size, '\n', stdin);
	if (len_buff == -1)
	{
		printf("ERROR NO COMMAND\n");
	}
	countp = mallocount(&buff, &count);
	if (countp->a == 0)
	{
		printf("ERROR NO COMMAND\n");
		return (1);
	}
	i = _strtok(&buff, countp);
	if (i < 0)
		printf("ERROR IN STRTOK\n");
	free(buff.b);
	return (0);
}
