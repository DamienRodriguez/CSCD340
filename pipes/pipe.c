#include "pipe.h"

int containsPipe(char *s)
{
    int i, count;
    for(i =0, count = 0;i < strlen(s); i++)
    {
        if(s[i]=='|')
        {
            count++;
        }
    }
    return count;
}// end containsPipe

void parsePipe(char *str, char **strPipe, int count) {
	int i;
	for(i = 0; i < count; i++)
		strPipe[i] = strsep(&str, "|");
} //

void pipeIt(char ***cmd, void (*forkFunct))
{
	int fd[2];
	pid_t pid;
	int fdd = 0;				/* Backup */

	while (*cmd != NULL) {
		pipe(fd);				/* Sharing bidiflow */
		if ((pid = fork()) == -1) {
			perror("fork");
			exit(1);
		} //if the process doesn't fork properly


		else if (pid == 0) { 
			dup2(fdd, 0);
			if (*(cmd + 1) != NULL) {
				dup2(fd[1], 1);
			}
			close(fd[0]);
			execvp((*cmd)[0], *cmd);
			exit(1);
		}
		else {
			wait(NULL); 		/* Collect childs */
			close(fd[1]);
			fdd = fd[0];
			cmd++;
		}
	}
}
