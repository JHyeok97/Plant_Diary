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

// 첫 페이지 프린트 하는 함수
void print_title(void)
{
}

// 파일 이름 정하는 함수
int get_date_file_name(void)
{
}

// 일기 내용 입력하는 함수
void scan_description(char description[])
{
}

// 일기를 txt 파일에 저장하는 함수
void put_diary(int date, char description)
{
}

// 일기를 txt 파일로부터 가져오는 함수
int get_diary(int date, char description[])
{
}

// 폴더 만드는 함수
void make_folder(void)
{
}

// 노드 추가 함수
void Add()
{
}

// 노드 삭제 함수
void Delete()
{
}

// 리스트 출력해주는 함수
void List()
{
}

// 원하는 정보 찾는 함수
Text_Name *Search()
{
}

// txt 파일 편집하는 함수
void txt_Edit()
{
}