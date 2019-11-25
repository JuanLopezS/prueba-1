#include "MyShell.h"
/**
 * envfxn - function will print environment
 * @buff: represents buffer to be voided
 * @commands: represents commands that will be voided
 * Return: function returns void
 */

int env1(char*buffer, char **command)
{
  int i, j, ret;

  if (command[1] == NULL)
    {
      ret = strcmp(command[0], "env");
      if (ret == 0)
	{
	  for(i= 0; environ[i] != '\0'; i++)
	    {
	      for(j = 0; environ[i][j] != '\0'; j++)
		{
		  write (1, &environ[i][j], 1);
		}
	      write(1, "\n", 1);
	    }
	  free(buffer);
	  free(command);
	  return(0);      
	}
      return(1);
    }
  return(1);
}


/**
    EXIT FUNCTION
 */


void exit1(char *buffer, char **command)
{
  int ret;

  if (command[1] == NULL)
    {
      ret = strcmp(command[0], "exit");
      if (ret == 0)
        {
          free(command);
	  free(buffer);
          exit(0);
        }
    }
}
