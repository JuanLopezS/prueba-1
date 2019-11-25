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

char  *validator(char **command)
{  
	int i;
	char delim[1]= ":", **token, *tok, *buffer;
	int len;
	char function[50];
	
	//scanf("%s", function);
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
	char *temp;
	temp = malloc((strlen(command[1]) + 1));
	if (temp == NULL)
	  return (NULL);
	
	//char *av[];
	
	while (token[i])
	{
	  DIR *d;
	  struct dirent *dir;
	  d = opendir(token[i]);
	  if (d)
	    {
	      while ((dir = readdir(d)) != NULL)
		{
		  if((strcmp(dir->d_name, command[1])) == 0)
		    {
		      strcpy(temp, token[i]);
		      strcat(temp, "/");
		      strcat(temp, dir->d_name);
		      printf("folder : %s\n", temp);
		      char *av[] = {temp,NULL};
		      closedir(d);
		      //execve(av[0],av,NULL);
		      return(temp);
		    }
		}
	      closedir(d);
	      i++;
	    }
	}
	temp = command[1];
	return(temp);
}
/**
  VALIDATOR EXEC

 */


int main(int argc,char *argv[])
{

  char *f;
 
  printf("argv = [%s] argv1 = [%s]\n",argv[0],argv[1]);
  
  f = validator(argv);
  printf("ret = [%s]\n", f);
  execve(f, argv, NULL);
  //free(temp);
  return(0);
}

