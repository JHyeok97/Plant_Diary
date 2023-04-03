#include "Text_Option.c"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 1000

typedef struct Text_Name
{
    char name[16];
    struct Text_Name *next
} Text_Name;

int main()
{
    char description[MAX_LENGTH] = "";

    while (1)
    {
        description[0] = '\0';
    }
}
