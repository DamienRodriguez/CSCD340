//
// Created by drodriguez on 4/30/19.
//

#include "history.h"

void displayHistory(FILE *fin, int mod, int totalRecords) {
    char temp[MAX];

    int i;
    for(i = 0; i < totalRecords; i++) {
        fgets(temp,MAX,fin);
        strip(temp);
        printf("%d %s\n", i+1, temp);
    }
}

char *returnCommand(FILE *fin, char *bang) {

    char temp[100];
    char *saveptr;

    strcpy(temp,strtok_r(temp, "!",&saveptr));


    int j = atoi(temp);
    int i;
    for(i = 0; i < j && !feof(fin); i++) {
        fgets(temp,100,fin);
    }
    return returnedCopy;
}