#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct Node
{
    char *name;
    struct Node *next;
} Node;

void Print_Title(void);
int Get_Date_File_Name(void);
void Scan_Description(char[]);
void Put_Diary(int, char[]);
int Get_Diary(int, char[]);