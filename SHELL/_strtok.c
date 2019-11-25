#include "MyShell.h"
/**
 MEMORY POINTERS 
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


char **function_strtok(char *buffer, int pointer)
{
	char **command;
	size_t i;
	char *tok;
	char *delim = " \n\t";

	command = malloc(sizeof(char *) * pointer);
	if (command == NULL)
	{
		free(buffer);
		return (NULL);
	}
	tok = strtok(buffer, delim);
	i = 0;
	while (tok)
	{
		command[i] = tok;
		tok = strtok(NULL, delim);
		i++;
	}
	command[i] = NULL;
	return (command);
}
