#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/types.h>
#include <sysexits.h>

typedef struct Node
{
    char *name;
    struct Node *next;
} Node;

void Print_Title();
void Print_folder();
void Print_Text(char *);
int Get_Date_File_Name();
void Scan_Description(char[]);
void Put_Diary(int, char[]);
int Get_Diary(int, char[]);
void Make_Folder(char *);
void Add(char *);
void Delete(char *);
void List();
// void txt_Edit();