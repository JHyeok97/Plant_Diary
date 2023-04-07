#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/types.h>
#include <sysexits.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

void Print_Title();
void Print_folder();
void Print_Text(char[]);
int Get_Date_File_Name();
void Scan_Description(char[]);
void Put_Diary(int, char[]);
int Get_Diary(int, char[]);
int Make_Folder(char[]);
int Delete_folder(char[]);
int Enter_folder(char[]);
int Find_List(char[]);
int Delete_file(int);