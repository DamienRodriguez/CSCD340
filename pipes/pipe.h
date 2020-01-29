#ifndef PIPE_H
#define PIPE_H

#include "../utils/requiredIncludes.h"
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int containsPipe(char *);
void parsePipe(char *, char**, int);
void pipeIt(char ***);

#endif
