#ifndef COMMAND_H_
#define COMMAND_H_

#include "../utils/requiredIncludes.h"

struct command {
	char *command;
};

typedef struct command Command;

void cleanTypeCommand(void *);

void *buildTypeCommand(FILE *);

void printTypeCommand(void *);

int compareCommands(const void *, const void *);

Command *buildCommandPassedIn(char *);

char *getCommand(void *ptr);

#endif
