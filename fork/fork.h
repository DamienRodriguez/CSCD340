#ifndef FORK_H
#define FORK_H

#include "../utils/requiredIncludes.h"
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

void forkIt(char **);

#endif

