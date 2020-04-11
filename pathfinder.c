#include "holberton.h"

char *pathfinder(char *command, char **envp)
{
	char *path = NULL;
	char *path2 = NULL;
	char *filename;
	char *cmd = "/";
	char *token = " ";
	int i = 0;
	int j;
	int k;

	strcat(cmd, command);
	while (envp[i] != NULL)
	{
		if (envp[i][0] == 'P' && envp[i][1]== 'A')
		{
			path = envp[i];
			for (j = 0; j <5; j++)
			{/*make it's own function*/
				path++;
			}
			path2 = path;
			token = strtok(path2, ":");
			while (token != NULL)
			{
				strcpy(filename, token);
				strcat(filename, cmd);
				if( access( filename, F_OK ) != -1 )
				{
					k = strlen(filename);
					filename = malloc((k) * sizeof(char));
					if (filename == NULL)
						return (NULL);
					return(filename);
				}
				token = strtok(NULL, ":");
			}
		}
	i++;
	}
	return (NULL);
}
