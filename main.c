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
	char *args[10], line[10], *finalpatharg;
	pid_t pid;
	int ex = 1, isat, check, times = 0;

	(void)argc;
	helper();
	isat = isatty(STDIN_FILENO);
	while (ex)
	{
		times++;
		ex = read_parse_line(args, line, isat);
		check = check_args(args, envp);
		finalpatharg = set_path(args, envp);
		if (finalpatharg && check)
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
			if (check)
				printerror(args, argv, times, isat);
	}
	return (0);
}
