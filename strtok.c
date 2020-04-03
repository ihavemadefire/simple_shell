#include "holberton.h"
/**
 * _strtok - breaks string up by spaces and puts each in seperate index
 * @buff: buffer struct from main for string
 * @count: dble struct used to malloc correct amount
 *
 * Return: int on succes or failure
 */
int _strtok(buffer *buff, dble *count)
{
	int j = 0;
	char **tokens;
	char *temp = buff->b;
	char *ttemp;
	int a = count->a, b = count->b;

	tokens = malloc(sizeof(char *) * count->b);
	if (tokens == NULL)
		return (-1);
	while (b >= 0)
	{
		tokens[j] = malloc(sizeof(char) * a);
		j++;
		b--;
	}
	tokens[j] = NULL;
	if (buff->b == NULL)
		return (1);
	j = 0;
	b  = count->b;
	ttemp = strtok(temp, " ");
	while (ttemp != NULL)
	{
		tokens[j] = ttemp;
		ttemp = strtok(NULL, " ");
		j++;
	}
	if (tokens[0])
		j = exec(tokens);
	if (j == 1)
		return (0);
	b = count->b;
	j = 0;
	return (0);
}
