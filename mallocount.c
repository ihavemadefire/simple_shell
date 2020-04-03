#include "holberton.h"
/**
 * _count - counts strlen and number of words
 * @buff: buffer struct used to count string
 * @count: dble struct set at {0, 0}
 *
 * Return: dble struct
 */
dble *mallocount(buffer *buff, dble *count)
{
	int i = 0, j = 0;
	char *string = buff->b;

	while (string[i])
	{
		while (string[i] != ' ' && string[i])
		{
			count->a += 1;
			i++;
		}
		if (string[i] == ' ')
			i++;
		count->b += 1;
		j++;
	}
	return (count);
}
