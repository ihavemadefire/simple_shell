#include "holberton.h"
/**
 * main - start of shell
 * @argc: arg count if needed
 * @argv: contains args
 * @envp: contains environment
 *
 * Return: int for success or failure
 */
int main(int argc, char **argv, char **envp)
{
	char *args[10];
	char line[100];
	pid_t pid;
	int ret = 0;

	(void)argc, (void)argv, (void)envp;

	while (read_parse_line(args, line))
	{
		pid = fork();
		if (pid < 0)
		{
			perror("FORK FAILED");
			exit(1);
		}
		if (pid == 0)
		{
			ret = execvp(args[0], args);
			if (ret != 0)
				printerror(args);
		}
		else
		{
			waitpid(pid, 0, 0);
		}
	}
	return (0);
}
