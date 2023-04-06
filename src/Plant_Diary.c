#include "MakeText.h"

#define MAX_LENGTH 1000

int main()
{
    int menu1, menu2, menu3, date, year, month, day;
    char folderName[10];
    char description[MAX_LENGTH] = "";

    while (1)
    {
        description[0] = '\0';
        Print_Title();
        scanf("%d", &menu1);
        system("clear");
        switch (menu1)
        {
        case 1:
            while (1)
            {
                Print_folder();
                // 폴더 리스트 출력 추가할 자리
                scanf("%d", menu2);

                switch (menu2)
                {
                case 1:
                    system("clear");
                    printf("추가할 폴더 이름을 입력하세요.\n");
                    puts(folderName);
                    Make_Folder(&folderName);
                    break;
                case 2: // 폴더 삭제할 함수 만들기
                case 3: // 폴더 입력하면 들어가는 함수 만들기
                case 4:
                    break;
                default:
                    system("clear");
                    printf("번호를 잘못 입력하셨습니다. 다시 입력하세요./\n");
                    break;
                }
                if (menu2 == 3)
                    break;
            }

            break;

        case 2:
            return 0;
        default:
            puts("잘못된 번호를 입력하셨습니다. 다시 입력하세요.\n");
            break;
        }
    }

    Print_Title();
}
