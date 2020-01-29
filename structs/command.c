#include "command.h"

void *buildTypeCommand(FILE *fin) {
	Command *this = (Command *)calloc(1,sizeof(Command));
	char input[MAX];

	fgets(input,MAX,fin);
	strip(input);
	this->command = (char *)calloc(strlen(input)+1,sizeof(char));
	strcpy(this->command,input);

	return this;
}

Command *buildCommandPassedIn(char *ptr) {
    Command *this = (Command *)calloc(1,sizeof(Command));
    this->command = (char *)calloc(strlen(ptr) + 1, sizeof(char));
    strcpy(this->command, ptr);

    return this;
}

void cleanTypeCommand(void *ptr) {
	Command *this = (Command *)ptr;
	
	free(this->command);
	this->command = NULL;
	
	free(this);
}

void printTypeCommand(void *ptr) {
	Command *this = (Command *)ptr;
	printf("%s\n",this->command);
}

int compareCommands(const void *ptr1, const void *ptr2) {
	Command *this = (Command *)ptr1;
	Command *that = (Command *)ptr2;

	return strcmp(this->command,that->command);
}

char *getCommand(void *ptr) {
    Command *this = (Command *) ptr;
    return this->command;
}
