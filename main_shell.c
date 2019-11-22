#include "myshell.h"
/**
 * main - super simple shell
 *
 * Return: nothing
 **/
int main(void)
{
        char *buffer = NULL, delim[3] = " \n\t", **command, *tok;
	int status, i, len, ex;
	pid_t pidC;

	while(1)
	{
	        write(1, "MyPrompt$ ", 10);
		buffer = validator_getline();
		if (buffer  == NULL)
			continue;
		len = _memory(buffer);
		command = malloc(sizeof(*command) * (len + 1));
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
			exit1(command);
			pidC = fork();
			if (pidC == -1)
			  {
			    perror("Error:");
			    return (-1);
			  }
			if (pidC == 0)
			{
				ex = execve(command[0], command, NULL);
				if(ex == -1)
					perror("Error");
				i = 0;
				while (command[i])
				  free(command[i++]);
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
    char *delim = " ";

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

  ret = strcmp(command[0], "exit");
  if (ret == 0)
    {
      while (command[i])
	free(command[i++]);
      free(command);
      exit(0);
    }
  return (0);
}
