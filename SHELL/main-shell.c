#include "MyShell.h"

/**
 * main - PROGRAM SHELL
 * Return: function will always return 0
 */

int main(void)
{
  char *buffer = NULL, **command; 
  int status, pointer, i, y, ex;
  pid_t pidC;
  struct stat st;

	while (1)
	{
	  write(1, "MyPrompt$ ", 10);
	  buffer = validator_getline();
	  if (!buffer)
	    continue;
	  pointer = _memory(buffer);
	  command = function_strtok(buffer, pointer);
	  exit1(buffer, command);
	  i = env1(buffer, command);
	  if(i == 0)
	    continue;
	  pidC = fork();
	  if (pidC == -1)
	    {
	      perror("Error Fork");
	      return(-1);
	    }
	  if (pidC == 0)
	    {
	      y = stat(command[0], &st);
	      if (y != 0)
		command[0] = get_path(command[0]);
	      ex = execve(command[0], command, NULL);
	      if (ex == -1)
		perror("Error Execve");
	      free(command);
	    }
	  else if (pidC > 0)
	    wait(&status);
	  free(buffer);
	}
	return (0);
}
