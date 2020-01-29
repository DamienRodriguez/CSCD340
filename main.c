#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./utils/myUtils.h"
#include <unistd.h>
#include "./cd/cd.h"
#include "./token/makeArgs.h"
#include "./process/process.h"
#include "./pipes/pipe.h"
#include "./utils/fileUtils.h"
#include "./linkedlist/linkedList.h"
#include "./linkedlist/listUtils.h"
#include "./history/history.h"
#include "./Path/changePath.h"

int HISTSIZE = 12;
int HISTFILECOUNT = 0;

void updateFile(LinkedList *, FILE *, char * (*getData)(void *));

int main() {

	int argc, pipeCount, bangFLAG;
    int pre, mid, post;
	char **argv = NULL;
	char *temp, in[100], *saveptr, s[100];
	char **prePipe, **midPipe, **postPipe;

    LinkedList *cmds = linkedList();

    bangFLAG = 0;
	FILE *history = fopen("foo.post_history","a+");


	HISTFILECOUNT = countRecords(history, 1);


	printf("command: ");
	fgets(in,MAX,stdin);
	strip(in);

	while(strcmp(in, "exit") != 0) {

		pipeCount = containsPipe(in); //this will give us number of pipes
		Command *temp2 = buildCommandPassedIn(in);
		addLast(cmds, buildNode_Type(temp2));
		
		if(pipeCount > 0) {
            argc = pipeCount + 1;

            char* strPiped[argc]; //gives us the spaces we need to get our pipes in
            parsePipe(in,strPiped, argc); //gives us 2 dim array of commands



            if(pipeCount == 1) {
                pre = makeargs(strPiped[0],&prePipe, ' ');
                post = makeargs(strPiped[1],&postPipe, ' ');


                char **company[2];
                company[0] = prePipe;
                company[1] = postPipe;


                pipeIt(company);

                clean(pre,prePipe);
                clean(post,postPipe);

            } else {

                pre = makeargs(strPiped[0], &prePipe, ' ');
                mid = makeargs(strPiped[1], &midPipe, ' ');
                post = makeargs(strPiped[2], &postPipe, ' ');

                char **crowd[3];
                crowd[0] = prePipe;
                crowd[1] = midPipe;
                crowd[2] = postPipe;

                pipeIt(crowd);

                clean(pre,prePipe);
                clean(mid, midPipe);
                clean(post,postPipe);
            }
		}
		
		else {






            if (strstr(in, "cd") != NULL) {
                temp = strtok_r(in, " ", &saveptr);  //grabs cd
                temp = strtok_r(NULL, " ", &saveptr); //grabs our destination
                changeDirectory(temp);
            }//cd check

	        else if (strstr(in, "history") != NULL)
                displayHistory(history, HISTSIZE, HISTFILECOUNT); //displays history from file

            else if (strstr(in, "!") != NULL) {
                char *returnedCommand = returnCommand(history,in);
                strip(returnedCommand);
                strcpy(in,returnedCommand); //puts our copied
                printf("Command returned: %s",in);
                bangFLAG = 1;

            }

            else if(strstr(s,"PATH=") != NULL)
            {
                if(strstr(s,"$") != NULL) {
                    changePath$(s);
                }
                else
                {
                    changePath(s);
                }
            }

            else {
                if(!bangFLAG) {
                    argc = makeargs(in, &argv, ' ');
                    if (argc != -1) {
                        if (strstr(argv[argc - 1], "&") != NULL)
                            forkItBackGround(argv);
                        else
                            forkIt(argv);
                    }
                    clean(argc, argv);
                    argv = NULL;
                }
            }

		}

		if(!bangFLAG) {
            printf("command: ");
            fgets(in, MAX, stdin);
            strip(in);
        }
		bangFLAG = 0;

	}
    updateFile(cmds, history, getCommand);

	clearList(cmds, cleanTypeCommand);
	free(cmds);
	cmds = NULL;

	fclose(history);
	return 0;
}

void updateFile(LinkedList *list, FILE *fp, char * (*getData)(void *)) {

    Node *cur = list->head->next; //first node of our new commands
    while(cur != NULL) {
        fprintf(fp, "%s\n", getData(cur->data)); //this should print our commands to our history file
        cur = cur->next; //move down the line
    }

}
