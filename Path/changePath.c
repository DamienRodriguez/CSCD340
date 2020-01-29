//
// Created by jessica on 4/30/19.
//

#include <stdlib.h>
#include "changePath.h"
#include <string.h>
void changePath(char* input)
{
    char* postEquals = strchr(input,':');
    setenv("PATH",postEquals,1);
}

void changePath$(char* input)
{
    char* postEquals = strchr(input,':');
    setenv("PATH",postEquals,1);
}



