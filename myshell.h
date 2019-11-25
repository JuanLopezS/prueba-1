#ifndef MY_SHELL_H
#define MY_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>

char *validator_getline(void);
int _memory(char *buffer);
int exit1(char **command);
char *validator_function(char **command);

#endif
