#include"list.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
/*
1�����õ�����
2����ת������
3���ϲ���������ĵ�����
4���жϵ������Ƿ��л���������ڵ㣿���ĳ��ȣ�
5���ж������������Ƿ��ཻ�����㣿
6��O(1)ʱ��ɾ���������һ���ڵ�
7�����ʱ�����ҵ�����������K���ڵ㣿
8�����ʱ����ɾ������������K���ڵ㣿
*/

void InitList(List plist)//��ʼ��������
{
	assert(plist != NULL);
	plist->next = NULL;
}

static Node *GetNode(int val)
{
	Node* pGet = (Node *)malloc(sizeof(Node));
	assert(pGet != NULL);
	pGet->data = val;
	pGet->next = NULL;
	return pGet;
}

bool Insert_head(List plist,int val)//ͷ�巨�����½��Ľڵ����ͷ������һ���ڵ�֮��
{
	Node *pGet = GetNode(val);
	pGet->next = plist->next;
	plist->next = pGet;
	return true;
}

bool Insert_tail(List plist,int val)//β�巨
{
	Node *cur = plist;//ָ��ͷ���  ����ǰ����Ϣ��
	while(cur->next != NULL)
	{
		cur = cur->next;
	}
	Node *pGet = GetNode(val);
	cur->next = pGet;
	return true;
}

bool Insert_pos(List plist,int pos,int val)//pos λ�ò���
{
	if(pos < 0 || pos > GetLength(plist))
	{
		return false;
	}
	Node *cur = plist;
	for(int i = 0;i <= pos-1;i++)
	{
		cur = cur->next;
	}
	Node *pGet = GetNode(val);
	pGet->next = cur->next;
	cur->next = pGet;
	return true;
}

Node *Search_pre(List plist,int key)//���� key ��ǰ��
{
	if(IsEmpty(plist))
	{
		return NULL;
	}
	Node *cur = plist;
	while(cur->next != NULL)
	{
		if(cur->next->data == key)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

bool Delete(List plist,int key)//ɾ�� key ������
{
	Node *p = Search_pre(plist,key);
	if(p == NULL)
	{
		return false;
	}
	Node *pDel = p->next;//ɾ���Ľڵ�
	p->next = pDel->next;
	free(pDel);
	pDel = NULL;
	return true;
}

bool IsEmpty(List plist)//�Ƿ�Ϊ��
{
	if(plist == NULL || plist->next == NULL)
	{
		return true;
	}
	return false;
}

void Destroy(List plist)//�ݻٺ���������ж�̬�����ڴ棩
{
	Node *pDel = NULL;
	while(plist->next != NULL)
	{
		pDel = plist->next;
		plist->next = pDel->next;
		free(pDel);
	}
	pDel = NULL;
}
//�õ�������ĳ���
int GetLength(List plist)
{
	int count = 0;
	Node *pCur = plist->next;
	while(pCur != NULL)
	{
		count++;
		pCur = pCur->next;
	}
	return count;
}

//��ӡ������
void Show(List plist)
{
	Node *pCur = plist->next;
	while(pCur != NULL)
	{
		printf("%d ",pCur->data);
		pCur = pCur->next;
	}
	printf("\n");
}