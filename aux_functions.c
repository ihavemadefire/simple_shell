#include "holberton.h"

/**
 * _atoi -   converts an ascii string into an integer
 *
 * @s: a passed string pointer
 *
 * Return: Return integer
 */

int _atoi(char *s)
{
	int result = 0;
	int sign = 1;
	int i = 0;

	if (*s == '\0')
		return (0);

	while (isNumericChar(*s) == 0)
		s++;
	if (s[0] == '-')
	{
		sign = -1;
		i++;
	}
	for (; isNumericChar(*(s + i)) != 0; ++i)
		result = (result * 10) + *(s + i) - '0';

	return (result * sign);
}
/**
 * isNumericChar -   converts an ascii string into an integer
 *
 * @x: a passed variable to check if the next char is numeric
 *
 * Return: Return integer
 */
int isNumericChar(char x)
{
	if (x >= '0' && x <= '9')
		return (1);
	else
		return (0);
}

/**
 *_strcmp - compares to strings
 *@s1: passed pointer to be compared
 *@s2: passed pointer to be compared
 *
 *
 *Return: returns 0 when strings match
 */

int _strcmp(char *s1, char *s2)
{
	int i;
	int j;
	int dif;

	for (i = 0; *(s1 + i) != '\0'; i++)
		;
	for (j = 0; j < i; j++)
	{
		if ((s1[j] - s2[j]) != 0)
		{
			dif = (s1[j] - s2[j]);
			break;
		}
		else
			dif = (0);
	}
	return (dif);
}

/**
 * _strlen - returns length of string
 *@s: passed pointer to be measured
 *
 *Return: length of string
 */

int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;

	return (i);
}

/**
 * _ptstr - returns length of string
 *@s: passed pointer to be printed
 *
 */
void _ptstr(char *s)
{
	int j;
	char *buff;

	j = _strlen(s);
	buff = s;
	write(STDOUT_FILENO, buff, j);
}
