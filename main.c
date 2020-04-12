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
	pid_t pid;
	int ex = 1, isat;

	(void)argc;

	isat = isatty(STDIN_FILENO);
	while (ex)
	{
		ex = read_parse_line(args, line, isat);
		finalpatharg = set_path(args, envp);
		if (finalpatharg != NULL)
		{
			pid = fork();
			if (pid < 0)
			{
				perror("FORK FAILED");
				exit(1);
			}
			if (pid == 0)
			{
				executepath(finalpatharg, args);
			}
			else
			{
				waitpid(pid, 0, 0);
			}
		}
		else
			printerror(args, argv, isat);
	}
	return (0);
}
