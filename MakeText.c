#include "MakeText.h"

// 첫 페이지 프린트 하는 함수
void Print_Title(void)
{
    char diary[] = {"식물 일기장"};

    puts(" ");
    printf("\t\t%s\n", diary);
    puts(" ");

    puts("1. 입력하기");
    puts("2. 끝내기");
}
// 파일 이름 정하는 함수
int Get_Date_File_Name(void)
{
}

// 일기 내용 입력하는 함수
void Scan_Description(char description[])
{
}

// 일기를 txt 파일에 저장하는 함수
void Put_Diary(int date, char description[])
{
    char filename[20];
    FILE *fp = NULL;
    scanf("%s",&filename);

    sprintf(filename, "%d", date);
    strcat(filename,".txt");
    fp=
    fprintf()
}

// 일기를 txt 파일로부터 가져오는 함수
int Get_Diary(int date, char description[])
{
}

// 폴더 만드는 함수
void Make_Folder(void)
{
    puts("폴더를 생성합니다.");
}
