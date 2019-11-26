#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

/**
 * main - execve example
 *
 * Return: Always 0.
 */
int main(void)
{
	char *argv[] = {"biqw", "-l", "/usr/", NULL};
	pid_t pidC;
	int ex, status;
	pid_t pid = getpid();
	pid_t ppid = getppid();

	while(1)
	{
		sleep(3);
		pidC = fork();
		sleep(3);
		if (pidC == -1)
		{
			perror("Error Fork");
			return(-1);
		}
		if (pidC == 0)
		{
			printf("soy hijo PID = %d\n", pid);
			ex = execve(argv[0], argv, NULL);
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

		//if (execve(argv[0], argv, NULL) == -1)
		//{
		//	perror("Error:");
		//}
		//printf("After execve\n");
	}
	printf("Out while\n");
	return (0);
}
