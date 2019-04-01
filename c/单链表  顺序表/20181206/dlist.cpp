//typedef struct DNode
//{
//	int data;
//	struct DNode *next;
//	struct DNode *prio;
//}DNode, *DList;
//void InitList(DList plist);
//bool Insert_head(DList plist, int val);
//bool Insert_tail(DList plist, int val);
//DNode *Search_pri(DList plist, int key);
//bool Delete(DList plist, int key);
//bool IsEmpty(DList plist);
//void Destroy(DList plist);
//int GetLength(DList plist);
//void Show(DList plist);
#include<stdio.h>
#include "dlist.h"
#include<assert.h>
#include<stdlib.h>
void InitList(DList plist)
{
	plist->next = NULL;
	plist->prio = NULL;
}
static DNode *GetNode(int val)
{
	DNode* pGet = (DNode *)malloc(sizeof(DNode));
	assert(pGet != NULL);
	pGet->data = val;
	pGet->next = NULL;
	pGet->prio = NULL;
	return pGet;
}
bool Insert_head(DList plist, int val)//头插
{
	DNode *pGet = GetNode(val);
	pGet->next = plist->next;
	if (pGet->next != NULL)
	{
		pGet->next->prio = pGet;
	}
	plist->next = pGet;
	pGet->prio = plist;
}
bool Insert_tail(DList plist, int val)
{
	DNode *cur = plist;//指向头结点  依赖前驱信息的
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	DNode *pGet = GetNode(val);
	cur->next = pGet;
	pGet->prio = plist;
	return true;
}
DNode *Search_pri(DList plist, int key)
{
	DNode *cur = plist;
	while (cur->next != NULL)
	{
		if (cur->next->data == key)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
bool Delete(DList plist, int key)
{
	p->next = pDel->next;
	pDel->next->
}
void Destroy(DList plist)
{
	DNode *pDel = NULL;
	while (plist->next != NULL)
	{
		pDel = plist->next;
		plist->next = pDel->next;
		free(pDel);
	}
	pDel = NULL;
}
