#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <dirent.h>


extern char **environ;

int _memory(char *buffer)
{
	int i , count = 2;
	char *delim = " ";

	for(i = 0; buffer[i] != '\0'; i++)
	{
		if (buffer[i] == delim[0])
			count++;
	}
	return (count);
}


char **function_strtok(char *buffer, int pointer)
{
        char **command;
        size_t i;
        char *tok;
        char *delim = " ";

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
char *validator_getline(void)
{
	char *buffer = NULL;
	size_t size = 0;
	ssize_t ret;

	ret = getline(&buffer, &size, stdin);
	if (!buffer)
	{
		perror("Error in Allocate Memory Buffer");
		return (NULL);
	}
	if (ret == 1)
	{
		free(buffer);
		return (NULL);
	}
	else if (ret == EOF)
	{
		free(buffer);
		perror("EOF");
		exit(0);
	}
	else
		return (buffer);
}

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





int main(void)
{
	char *buffer;
	int count,j, i = 0;
	char **command;
	while(1)
	{
		i = 0;
		printf("Write: ");
		buffer = validator_getline();
		if(buffer == 0)
		continue;
		count = _memory(buffer);
		command = function_strtok(buffer, count);
		exit1(buffer, command);
		j = env1(buffer, command);
		if(j == 0 || command == 0)
			continue;
		while(command[i])
		{
			printf("Com[%d] %s\n",i,command[i]);
			i++;
		}
		pid_t pidC;
		int ex, status;
		pid_t pid = getpid();
		pid_t ppid = getppid();

		pidC = fork();
		if (pidC == -1)
		{
			perror("Error Fork");
			return(-1);
		}
		if (pidC == 0)
		{
			printf("soy hijo PID = %d\n", pid);
			ex = execve(command[0], command, NULL);
			printf("After execve\n");
			if (ex == -1)
				perror("Error Execve");
		}
		else if (pidC > 0)
		{
			printf("Soy Padre PID = %d\n", ppid);
			wait(&status);
		}
		printf("sali del proceso hijo\n");
		free(command);
		free(buffer);
	}
	return(0);
}
