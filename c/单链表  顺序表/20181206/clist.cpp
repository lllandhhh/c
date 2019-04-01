#include<stdio.h>
#include"clist.h"
#include<assert.h>
#include<stdlib.h>
void InitList(CList plist)
{
	plist ->next= plist;
}
static CNode *GetNode(int val)
{
	CNode* pGet = (CNode *)malloc(sizeof(CNode));
	assert(pGet != NULL);
	pGet->data = val;
	pGet->next =pGet ;
	return pGet;
}
bool Insert_head(CList plist, int val)// ͷ��
{
	CNode *pGet = GetNode(val);
	pGet->next = plist->next;
	plist->next = pGet;
	return true;
}
bool Insert_tail(CList plist, int val)//β�巨
{
	CNode *cur = plist;//ָ��ͷ���  ����ǰ����Ϣ��
	while (cur->next != plist)
	{
		cur = cur->next;
	}
	CNode *pGet = GetNode(val);
	cur->next = pGet;
	return true;
}
CNode *Search_pri(CList plist, int key)//����ǰ��
{
	CNode *cur = plist;
	while (cur->next != plist)
	{
		if (cur->next->data == key)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
bool Delete(CList plist, int key)//ɾ��
{
	CNode *cur = plist;
	while (cur->next != plist)
	{
		if (cur->data == key - 1)
		{
			cur->next = cur->next->next;
			break;
		}
		else cur = cur->next;
	}
	return false;
}
int GetLength(CList plist)//�õ�����
{
	CNode *cur = plist;//ָ��ͷ���  ����ǰ����Ϣ��
	int m = 0;
	while (cur->next != plist)
	{
		cur = cur->next;
		m++;
	}

	printf("%d", m);
	return 0;
}
void Show(CList plist)//��ӡ������
{
	CNode *cur = plist;//ָ��ͷ���  ����ǰ����Ϣ��
	while (cur->next != plist)
	{
		cur = cur->next;
		printf("%d", cur->data);
	}
}