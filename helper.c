#include "holberton.h"
/**
 * helper - checks for ctrl C command signal
 *
 * Return: void
 */
void helper(void)
{
	signal(SIGINT, handler);
}

/**
 * handler - prints line instead of exit
 * @num: needed for signal but not used
 *
 * Return: void
 */
void handler(int num)
{
	(void)num;

	write(STDOUT_FILENO, "\n", 1);
	printline();
}
