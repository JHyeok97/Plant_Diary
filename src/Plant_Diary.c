#include "MakeText.h"

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
                chdir("store");
                Print_folder();
                Find_List_dir(folderName);
                scanf("%d", &menu2);

                switch (menu2)
                {
                case 1:
                    system("clear");
                    printf("추가할 폴더 이름을 입력하세요.\n");
                    scanf("%s", folderName);
                    Make_Folder(folderName);
                    break;
                case 2:
                    printf("삭제할 폴더 이름을 입력하세요.\n");
                    scanf("%s", folderName);
                    Delete_folder(folderName);
                    break;
                case 3: // 폴더 입력하면 들어감
                    printf("원하는 폴더 이름을 입력하세요.\n");
                    scanf("%s", folderName);
                    Enter_folder(folderName);
                    system("clear");

                    while (1)
                    {
                        Print_Text(folderName);
                        Find_List_txt(folderName);
                        scanf("%d", &menu3);
                        switch (menu3)
                        {
                        case 1:
                            system("clear");
                            Scan_Description(description);
                            date = Get_Date_File_Name();
                            Put_Diary(date, description);
                            system("clear");
                            printf("\n\n~~![%d.txt] 일기 작성 성공!~~\n\n", date);
                            break;
                        case 2:
                            printf("삭제하고 싶은 날짜를 입력해주세요 (YYYY MM DD): ");
                            scanf("%d %d %d", &year, &month, &day);
                            Delete_file(date);
                            break;
                            // 파일 삭제 함수 자리

                        case 3:
                            printf("확인하고 싶은 날짜를 입력해주세요 (YYYY MM DD): ");
                            scanf("%d %d %d", &year, &month, &day);
                            system("clear");
                            date = (year * 10000 + month * 100 + day);

                            if (Get_Diary(date, description))
                                printf("\n\n%d.txt의 정보:\n%s\n\n(그만 보려면 아무 키나 누르세요.)", date, description);

                            else
                                puts("그 날에는 일기를 작성하지 않았습니다\n(아무 키나 눌러 이전 화면으로 돌아가기.)\n");

                            getchar();
                            getchar();
                            system("clear");
                            break;
                        case 4:
                            chdir("..");
                            break;

                        default:
                            puts("잘못된 번호를 입력하셨습니다. 다시 입력해주세요.");
                            system("clear");
                            break;
                        }
                        if (menu3 == 4)
                            break;
                    }
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
