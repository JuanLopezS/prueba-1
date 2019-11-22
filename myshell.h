#ifndef MY_SHELL_H
#define MY_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

char *validator_getline(void);
int _memory(char *buffer);
int exit1(char **command);

#endif
