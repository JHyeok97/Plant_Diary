#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/stat.h>

typedef struct Node
{
    char *name;
    struct Node *next;
} Node;

void Print_Title();
int Get_Date_File_Name();
void Scan_Description(char[]);
void Put_Diary(int, char[]);
int Get_Diary(int, char[]);
void Add(char *);
void Delete(char *);
void List();
// void txt_Edit();