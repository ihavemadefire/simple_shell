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
	int ex = 1, isat, check, times = 0, status, ex_status;

	(void)argc;
	helper(), isat = isatty(STDIN_FILENO);
	while (ex)
	{
		times++, ex = read_parse_line(args, line, isat);
		if (ex != 2)
		{
			check = check_args(args, envp);
			finalpatharg = set_path(args, envp);
		}
		if (finalpatharg && check && ex == 1)
		{
			pid = fork();
			if (pid < 0)
			{
				perror("FORK FAILED"), exit(1);
			}
			if (pid == 0)
			{
				executepath(finalpatharg, args);
			}
			else
			{
				waitpid(pid, &status, 0);
				if (WIFEXITED(status))
					ex_status = WEXITSTATUS(status);
			}
		}
		else
		{
			exit_func(ex, ex_status, finalpatharg);
			if (check)
				printerror(args, argv, times);
		}
	}
	return (0);
}
