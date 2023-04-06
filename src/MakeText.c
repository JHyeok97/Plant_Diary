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

// txt 파일을 지정한 폴더에 저장할 수 있도록 수정//
void Put_Diary(int date, char description[])
{
  char filename[20]; // 문자열 변수 설정
  FILE *fp = NULL;   // FILE 포인터 변수 선언

  sprintf(filename, "%d", date);  // filename에 날짜 입력
  strcat(filename, ".txt");       // strcat 함수로 붙여넣기
  fp = fopen(filename, "w");      // file열어 작성하기
  fprintf(fp, "%s", description); // 내용
  fclose(fp);
}

// 일기를 txt 파일로부터 가져오는 함수
int Get_Diary(int date, char description[])
{
}

// 폴더 만드는 함수
void Make_Folder(char *Folder_Name)//표준 입력 장치로 받은 이름
{
  if (mkdir(Folder_Name, 0777) == 0) // 입력받은 이름으로 폴더를 생성한다(0777->읽기, 쓰기, 실행을 가능하게 하는 값.)
  {
    putchar(Folder_Name);
    printf("폴더를 생성하였습니다.");
  }
  else 
  {
    Puts("폴더 생성 실패");
  }
  return 0;
}
