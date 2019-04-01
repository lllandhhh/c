#include<stdio.h>
#include"link.h"
#include<stdlib.h>
void InitList(List plist)//��ʼ��������
{
	plist->next = NULL;
}
static Node  *GetNode(int val)
{
	Node * pGet = (Node *)malloc(sizeof(Node));
	pGet->data = val;
	pGet->next = NULL;
}
bool Insert_head(List plist, int val)//ͷ�巨
{
	Node * pGet = GetNode(val);
	pGet->next = plist->next;
	plist->next = pGet;
	return true;
}

bool Insert_tail(List plist, int val)//β�巨
{
	Node *cur = plist;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	Node *pGet = GetNode(val);
	cur->next = pGet;
	return true;
}
bool Insert_pos(List plist, int pos, int val);//pos λ�ò���                                                                                ��ҵ

Node *Search_pre(List plist, int key)//���� key ��ǰ��==��ַ
{
	Node *cur = plist;
	while (cur->next != NULL)
	{
		if (cur->next->data == key)
			return cur;
		else cur = cur->next;
	}
	return NULL;
}
bool Delete(List plist, int key);//ɾ�� key ������

bool IsEmpty(List plist);//�Ƿ�Ϊ��

void Destroy(List plist);//�ݻٺ���������ж�̬�����ڴ棩

int GetLength(List plist);//�õ�������ĳ���

void Show(List plist);//��ӡ������
