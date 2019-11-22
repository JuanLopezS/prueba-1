#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>

/**
 * main - prints the environment
 *
 * Return: Always 0.
 */
int main(int ac, char **av, char **env)
{
	int i;
	char delim[1]= ":", **token, *tok, *buffer;
	int len;
	char *function = "hdparm";
	i = 0;

	len = printf("%s\n", getenv("PATH"));

	buffer = getenv("PATH");
	
	token = malloc(len * sizeof(*token));
	if(token == NULL)
		perror("error allocated memory");
	else
	{
		tok = strtok(buffer, delim);
		i = 0;
		while (tok)
		{
			token[i] = tok;
			tok = strtok(NULL, delim);
			i++;
		}
		token[i] = 0;
		i = 0;
		while(token[i] != NULL)
		{
			printf("token[%d]: %s\n", i, token[i]);
			i++;
		}
	}
	i = 0;
	while (token[i])
	{
	  DIR *d;
	  struct dirent *dir;
	  d = opendir(token[i]);
	  if (d)
	    {
	      while ((dir = readdir(d)) != NULL)
		{
		  if((strcmp(dir->d_name, function)) == 0)
		    printf("folder : %s/%s\n", token[i],dir->d_name);
		}
	      closedir(d);
	      i++;
	    }
	}
	return(0);
}
