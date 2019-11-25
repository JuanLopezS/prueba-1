#ifndef MYSHELL_H
#define MYSHELL_H

#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <dirent.h>


#define BUFFERSIZE 1024

extern char **environ;

char *validator_getline(void);
int _memory(char *buff);
char **function_strtok(char *buff, int pointer);
void exit1(char *buffer, char **commands);
int env1(char *buff, char **commands);


int _strcmp(char *s1, char *s2);

char *_getenv(char *stri);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);

int _strcmp(char *s1, char *s2);
char *get_path(char *command);
char *_strcat(char *dest, char *src);
int _strlen(char *s);

#endif
