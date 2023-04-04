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

//폴더 페이지 프린트하는 함수
void Print_folder(void){

 char diary[] = {"식물 일기장"};

    puts(" ");
    printf("\t\t%s\n", diary);
    puts(" ");

    puts("1. 폴더 추가");
    puts("2. 폴더 삭제");
    puts("3. 이전 페이지\n\n");

}

//텍스트를 프린트하는 함수
void Print_Text(char *folder_name){
     
    puts(" ");
    printf("\t\t%s\n", &folder_name);
    puts(" ");

    puts("1. 일기 작성");
    puts("2. 일기 삭제");
    puts("3. 처음 화면\n\n");
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
    
    sprintf(filename, "%d", date);
    strcat(filename,".txt");
    fp=fopen(filename, "w");
    fprintf(fp,"%s",description);
    fclose(fp);
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
