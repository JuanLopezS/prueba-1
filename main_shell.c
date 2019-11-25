#include "myshell.h"
/**
 * main - super simple shell
 *
 * Return: nothing
 **/
int main(void)
{
  char *buffer = NULL, delim[3] = " \n\t", **command, *tok, *funct;
	int status, i, len, ex;
	pid_t pidC;

	while(1)
	{
	        write(1, "MyPrompt$ ", 10);
		buffer = validator_getline();
		if (buffer  == NULL)
			continue;
		len = _memory(buffer);
		command = malloc(sizeof(char *) * len);
		if(command == NULL)
		{
			perror("Error allocated memory");
			continue;
		}
		else
		{
			tok = strtok(buffer, delim);
			while (tok)
			{
				command[i] = tok;
				tok = strtok(NULL, delim);
				i++;
			}
			command[i] = 0;
			printf("c[0]= %s\n",command[0]);
			exit1(command);
			
			funct = validator_function(command);
			//strncpy(funct, command[0],100);
			//printf("c[1]= %s, f = %s\n",command[0], funct);
			//funct = command[0];
			pidC = fork();
			if (pidC == -1)
			  {
			    perror("Error:");
			    return (-1);
			  }
			if (pidC == 0)
			{
			  ex = execve(funct, command, NULL);
				if(ex == -1)
				      perror("Error Command");
				  
				i = 0;
				free(command);
			}
			else
			{
				wait(&status);
			}
		}
		free(buffer);
		i = 0;
	}
	return (0);
}


/**
VALIDATOR _ FUNCTION

 */
char *validator_function(char **command)
{
        int i;
	char delim[1]= ":", **token, *tok, *buffer;
	int len;
	char function[50];
	char *temp;
	
	//buffer = getenv("PATH");
	//len = strlen(buffer);
	i = 0;

	buffer = getenv("PATH");
	len = _memory(buffer);
	token = malloc(len * sizeof(char*));
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
	}
	i = 0;
	
	temp = malloc((strlen(command[0]) + 1));
	if (temp ==NULL)
	  return(NULL);
	while (token[i])
	{
	  DIR *d;
	  struct dirent *dir;
	  d = opendir(token[i]);
	  if (d)
	    {
	      while ((dir = readdir(d)) != NULL)
		{
		  if((strcmp(dir->d_name, command[0])) == 0)
		    {
		      strcpy(temp, token[i]);
		      strcat(temp, "/");
		      strcat(temp, dir->d_name);
		      printf("folder : %s\n", temp);
		      closedir(d);
		      free(token);
		      return(temp);

		      // printf("folder : %s\n", temp);
		      //char *av[] = {temp,NULL};
		      //execve(av[0],av,NULL);
		    }
		}
	      closedir(d);
	      i++;
		
	    }
	  
	}
	free(token);
	temp = command[0];
	return(temp);
}

	



/**

VALIDATOR _ GETLINE

*/

char *validator_getline(void)
{

	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t ret;

	ret = getline(&buffer, &bufsize, stdin);
	if(!buffer)
	{
		perror("Error in Allocate Memory Buffer");
		return(NULL);
	}
	if(ret == EOF)
	{
		free(buffer);
		perror("EOF");
		exit(0);
	}
	if(ret == 1)
	{
		free(buffer);
		return(NULL);
	}
	return(buffer);
}


/**

_memory


*/

int _memory(char *buffer)
{
    int i , j, count = 1;
    char *delim = " :";

    for(i = 0; buffer[i] != '\0'; i++)
      {
	for (j = 0; delim[j] != '\0'; j ++)
	  {
	    if (buffer[i] == delim[j])
	      count++;
	  }
      }
    return (count);
}

/**

_exit

 */

int exit1(char **command)
{
  int ret, i = 0;
  
  if (command[1] == NULL)
    {
      ret = strcmp(command[0], "exit");
      if (ret == 0)
	{
	  free(command);
	  exit(0);
	}
    }
 return (0);
}
