#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
extern char **environ;
/**
 * main - prints the environment
 *
 * Return: Always 0.
 */

char *_getenv(const char *env)
{
    int i = 0, n = 0;
    char *temp, *res;

    i = 0;
    while (environ[i] != NULL)
      {
	if (strncmp(environ[i], env,4) == 0)
	  temp = environ[i];
	i++;
      }

    while (temp[n] != '\0')
      {
	if (strcmp(temp, env) == 0)
	  res = strstr(temp, "/");
	n++;
      }
    return (res);
}
  

int main(void)
{
	int i;
	char delim[1]= ":", **token, *tok, *buffer;
	int len;
	char function[50];
	char **name;

	scanf("%s", function);

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
	char temp[50];
	
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
		    {
		      strcpy(temp, token[i]);
		      strcat(temp, "/");
		      strcat(temp, dir->d_name);
		      printf("folder : %s\n", temp);
		      char *av[] = {temp,NULL};
		      execve(av[0],av,NULL);
		    }
		}
	      closedir(d);
	      i++;
		
	    }
	}
	
	return(0);
}
/**
  VALIDATOR EXEC

 */

