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
        system("clear");
        Print_Title();
        scanf("%d", &menu1);
        system("clear");
        switch (menu1)
        {
        case 1:
            while (1)
            {
                system("clear");
                Print_folder();
                // 폴더 리스트 출력 추가할 자리
                scanf("%d", &menu2);

                switch (menu2)
                {
                case 1:
                    system("clear");
                    chdir("store");
                    printf("추가할 폴더 이름을 입력하세요.\n");
                    scanf("%s", folderName);
                    Make_Folder(folderName);
                    break;
                case 2:
                    printf("삭제할 폴더 이름을 입력하세요.\n");
                    scanf("%s", folderName);
                    Delete_folder(folderName);
                    break;
                case 3: // 폴더 입력하면 들어가는 함수 만들기
                    printf("원하는 폴더 이름을 입력하세요.\n");
                    scanf("%s", folderName);
                    Enter_folder(folderName);
                    system("clear");
                    Print_Text(folderName);
                    break;
                case 4:
                    break;
                default:
                    system("clear");
                    printf("번호를 잘못 입력하셨습니다. 다시 입력하세요./\n");
                    break;
                }
                if (menu2 == 4)
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
