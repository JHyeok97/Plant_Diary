#include "MakeText.h"

Node *head = NULL;

// 노드 추가 함수
void Add(char *name)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->name = (char *)malloc(strlen(name) + 1);
    strcpy(new_node->next, name) = head;
    head = new_node;
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