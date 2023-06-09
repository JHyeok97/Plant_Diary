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

    puts("1. 폴더 추가\t2. 폴더 삭제\t3. 폴더 들어가기\t4. 이전 페이지\n\n");
}

// 텍스트를 프린트하는 함수
void Print_Text(char foldername[])
{
    puts(" ");
    puts(" ");
    printf("\t\t");
    puts(foldername);
    puts(" ");
    puts(" ");

    puts("1. 식물 일기 작성\t2. 식물 일기 삭제\t3. 식물 일기 보기\t4. 이전 화면\n\n");
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
    int ch;
    unsigned int index = 0;
    char guide[] = "일기를 입력하세요. (종료하려면 _ 입력 후 Enter.)";
    const char *exit = "_";

    getchar();
    printf("%s(0/%d)\n", guide, MAX_LENGTH - 1);

    // getchar() 내 enter(\n) 입력, MAX_LENGTH 초과, EOF 일 때 입력 종료
    while ((ch = getchar()) != EOF)
    {
        description[index] = ch;
        index = strlen(description);

        fflush(stdout);
        system("clear");

        printf(
            "%s(%d/%d):\n%s",
            guide, index,
            MAX_LENGTH - 1, description);

        if (index + 1 == MAX_LENGTH - 1)
        {
            printf("\n글자 제한을 초과하여 작성을 종료하고 저장합니다.");
            break;
        }
        else if (strstr(description, exit))
        {
            printf("\nEnter 입력, 저장 후 종료");
            break;
        }
    }

    description[index + 1] = '\0';
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

    while (fgets(description, MAX_LENGTH, fp) != NULL)
    {
        printf("%s", description);
    }

    fclose(fp);

    return 1;
}

// 폴더 만드는 함수
int Make_Folder(char foldername[]) // 표준 입력 장치로 받은 이름
{
    if (mkdir(foldername, 0777) == 0) // 입력받은 이름으로 폴더를 생성한다(0777->읽기, 쓰기, 실행을 가능하게 하는 값.)
    {
        puts(foldername);
        printf("폴더를 생성하였습니다.");
    }
    else
    {
        puts("폴더 생성 실패");
        return 1;
    }
    return 0;
}

int Enter_folder(char foldername[]) // 폴더 이름 받아서 해당 폴더로 이동
{
    int result = chdir(foldername); // foldername 경로로 이동

    if (result == 0) // 정상적으로 함수가 작동할 시 0의 값을 반환함
    {
        printf("폴더 이동 성공");
    }
    else
    {
        printf("폴더 이동 실패");
    }
    return 0;
}

int Delete_folder(char foldername[])
{
    int result = rmdir(foldername);
    if (result == -1)
    {
        printf("폴더 삭제 실패");
        return 1;
    }
    return 0;
}

// txt 파일 삭제 함수
int Delete_file(int date)
{
    char filename[20];

    system("clear");
    sprintf(filename, "%d", date);
    strcat(filename, ".txt");

    if (remove(filename) == 0)
    {
        printf("%s 파일 삭제 성공\n", filename);
        return 0;
    }
    else
    {
        printf("%s 파일 삭제 실패\n", filename);
        return 1;
    }
}

int Find_List_dir(char foldername[])
{
    char file_name[256];
    char folder_path[256];

    // folder_path main 입력 된 파일 명 folder_path로 입력, size 크기 지정
    snprintf(folder_path, sizeof(folder_path), "%s", foldername);

    struct dirent *find_data;
    DIR *find_handle;

    // 입력 된 dir 파일명을 find_handle로 입력
    find_handle = opendir(foldername);

    if (find_handle == NULL) // find_handle 내 파일명(DIR 구조체의 d_name) 없는 경우
    {
        printf("파일 없음\n");
        return 1;
    }

    while ((find_data = readdir(find_handle)) != NULL)
    {
        snprintf(file_name, sizeof(file_name), "%s", find_data->d_name);
        if (find_data->d_type == DT_DIR && strcmp(file_name, ".") != 0 && strcmp(file_name, "..") != 0)
        {
            printf("%s\n", file_name);
        }
    }

    closedir(find_handle); // 열린 dir을 닫아 주는 함수 DIR* find_handle로 지정 되어 find_handle 입력
    return 0;
}

int Find_List_txt(char foldername[])
{
    char file_name[256];
    char folder_path[256];

    // folder_path main 입력 된 파일 명 folder_path로 입력, size 크기 지정
    snprintf(folder_path, sizeof(folder_path), "%s", foldername);

    struct dirent *find_data;
    DIR *find_handle;

    // 입력 된 dir 파일명을 find_handle로 입력
    find_handle = opendir(foldername);

    if (find_handle == NULL) // find_handle 내 파일명(DIR 구조체의 d_name) 없는 경우
    {
        printf("파일 없음\n");
    }

    while ((find_data = readdir(find_handle)) != NULL) // readdir 함수 #include <dirent.h> 된 find_handle 내 값의 dir을 출력
    {
        // file_name으로 find_data의 struct dirent의 구조체 파일명 관리(char) d_name의 값을 file name으로 입력
        snprintf(file_name, sizeof(file_name), "%s", find_data->d_name);
        // if (strstr(file_name, ".txt") != NULL) // ststr 문자열을 조합하는 함수 입력 받은 file_name과 ".txt"를 병합하여 dir 내 *.txt만을 출력하도록 조건 입력
        {
            printf("%s\n", file_name);
        }
    }

    closedir(find_handle); // 열린 dir을 닫아 주는 함수 DIR* find_handle로 지정 되어 find_handle 입력
}