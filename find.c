/*
 * C Program to List Files in Directory
 */
#include <dirent.h>
#include <stdio.h>

int main(void)
{
	DIR *d;
	struct dirent *dir;
	char *s = "pwd";
	
	d = opendir("/bin");
	if (d)
	{
		while ((dir = readdir(d)) != NULL)
		{
		  if(dir->d_name == s)
			printf("[%s]\n", dir->d_name);
		}
		closedir(d);
	}
	return(0);
}
