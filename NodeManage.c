#include "MakeText.h"

Node *head = NULL;

// 노드 추가 함수
void Add(char *name)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->name = (char *)malloc(strlen(name) + 1);
    strcpy(new_node->name, name);
    new_node->next = head;
    head = new_node;
}

// 노드 삭제 함수
void Delete(char *name)
{
    Node *current = head;
    Node *previous = NULL;

    while (current != NULL)
    {
        if (strcmp(current->name, name) == 0)
        {
            if (previous == NULL)
            {
                head = current->next;
            }
            else
            {
                previous->next = current->next;
            }
            free(current->name);
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

// 리스트 출력해주는 함수
void List()
{
}

// 원하는 정보 찾는 함수
Node *txt_Search()
{
    int year, month, day, date;
    Node *temp;
    temp = head;

    printf("날짜를 입력해주세요(YYYY MM DD):\n");
    scanf("%d %d %d", &year, &month, &day);
    date = (year * 10000 + month * 100 + day);
    system("clear");

    for (int i = 20230401; i <= date; i++)
    {
        temp->next;
    }

    if (temp == 0)
    {
        printf("찾으시는 기록이 없습니다.");
        return 0;
    }
    system("clear");

    for (int i = 1; temp != NULL; i++)
    {
        Node *temp = head;
        printf("kk");
    }
}

// txt 파일 편집하는 함수
void txt_Edit()
{
}