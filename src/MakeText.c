#include "MakeText.h"

#define MAX_LENGTH 1000

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

// 폴더 페이지 프린트하는 함수
void Print_folder(void)
{
    char diary[] = {"식물 일기장"};
// 폴더 페이지 프린트하는 함수
void Print_folder(void)
{
    char diary[] = {"식물 일기장"};

    puts(" ");
    printf("\t\t%s\n", diary);
    puts(" ");

    puts("1. 폴더 추가");
    puts("2. 폴더 삭제");
    puts("3. 이전 페이지\n\n");
}

// 텍스트를 프린트하는 함수
void Print_Text(char *folder_name)
{

    puts(" ");
    printf("\t\t%s\n", folder_name);
    puts(" ");

    puts("1. 일기 작성");
    puts("2. 일기 삭제");
    puts("3. 처음 화면\n\n");
}

// 파일 이름 정하는 함수
// time_t #include <time.h>을 참조하는 구조체를 기준으로 파일 이름 자동 출력
int Get_Date_File_Name(void)
{
    int year, month, day;
    struct tm *t;
    time_t timer;

    timer = time(NULL);
    t = localtime(&timer);

    year = t->tm_year + 1900;
    month = t->tm_mon + 1;
    day = t->tm_mday;

    return (year * 10000 + month * 100 + day);
}

// 일기 내용 입력하는 함수
void Scan_Description(char description[])
{
}

// 일기를 txt 파일에 저장하는 함수

// txt 파일을 지정한 폴더에 저장할 수 있도록 수정//
void Put_Diary(int date, char description[])
{
    char filename[20]; // 문자열 변수 설정
    FILE *fp = NULL;   // FILE 포인터 변수 선언

    sprintf(filename, "%d", date);  // filename에 날짜 입력
    strcat(filename, ".txt");       // strcat 함수로 붙여넣기
    fp = fopen(filename, "w");      // file열어 작성하기
    fprintf(fp, "%s", description); // 내용 작성
    fclose(fp);
}

// 일기를 txt 파일로부터 가져오는 함수
int Get_Diary(int date, char description[])
{
    char filename[20];
    FILE *fp;

    sprintf(filename, "%d", date);
    strcat(filename, ".txt"); // 자료형 파일과 문자 조합 함수
    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        return 0;
    }

    fgets(description, MAX_LENGTH, fp);
    fclose(fp);

    return 1;
}

// 폴더 만드는 함수
void Make_Folder(void)
{
    puts("폴더를 생성합니다.");


}
