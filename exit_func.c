#include "holberton.h"

/**
 * exit_func - exits shell correctly
 * @ex: number returned from parse_line
 * @ex_status: number returned from fork if failed
 * @finalpatharg: check if path is NULL
 *
 * Return: void
 */
void exit_func(int ex, int ex_status, char *finalpatharg)
{
	if (ex == 0)
	{
		if (finalpatharg == NULL)
			_exit(127);
		else
			_exit(ex_status);
	}
	if (ex == 2)
		_exit(0);
}
