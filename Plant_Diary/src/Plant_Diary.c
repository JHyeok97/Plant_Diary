#include "MakeText.h"
#include "MakeText.c"
#define MAX_LENGTH 1000

int main()
{
    int menu, date, year, month, day;
    char description[MAX_LENGTH] = "";

    while (1)
    {
        description[0] = '\0';
        Print_Title();
        scanf("%d", &menu);
        system("clear");
        switch (menu)
        {
        case 1:

        case 2:
            return 0;
        default:
            puts("잘못된 번호를 입력하셨습니다. 다시 입력하세요.\n");
            break;
        }
    }

    Print_Title();
}
