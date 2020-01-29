//
// Created by jessica on 4/28/19.
//

#include <string.h>
#include "redirect.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>
#include <fcntl.h>

void redirectStdout(char* s)
{
    char *token;
    char ** copy = NULL;
    char* command, fileName,*saveptr;
    command = strtok_r(s,"<",&saveptr);
    fileName = strtok_r(NULL,"<",&saveptr);
    pid_t pid = fork();
    if(pid != 0)
    {
        waitpid(pid,NULL,0);
    }
    else {
        int in = open(fileName, O_WRONLY | O_CREAT | O_APPEND);
        dup2(in, 1);
        execlp(command,command,NULL);
        write(in,command,255);
        close(in);

    }
}

void redirectStdin(char* s)
{
    char* command, FileName,*saveptr;
    command = strtok_r(s,">",&saveptr);
    FileName = strtok_r(NULL,">",&saveptr);
    pid_t pid = fork();
    if(pid != 0)
    {
        waitpid(pid,NULL,0);
    }
    else {
        int out = open(FileName, O_WRONLY | O_CREAT);
        dup2(out, 1);
        execlp(command,command,NULL);
        close(out);
    }

}
