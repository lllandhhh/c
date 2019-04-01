#include"list.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
/*
1、逆置单链表
2、反转单链表
3、合并两个有序的单链表
4、判断单链表是否有环？环的入口点？环的长度？
5、判断两个单链表是否相交？交点？
6、O(1)时间删除单链表的一个节点
7、最快时间内找到单链表倒数第K个节点？
8、最快时间内删除单链表倒数第K个节点？
*/

void InitList(List plist)//初始化单链表
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

bool Insert_head(List plist,int val)//头插法：把新建的节点插入头结点和下一个节点之间
{
	Node *pGet = GetNode(val);
	pGet->next = plist->next;
	plist->next = pGet;
	return true;
}

bool Insert_tail(List plist,int val)//尾插法
{
	Node *cur = plist;//指向头结点  依赖前驱信息的
	while(cur->next != NULL)
	{
		cur = cur->next;
	}
	Node *pGet = GetNode(val);
	cur->next = pGet;
	return true;
}

bool Insert_pos(List plist,int pos,int val)//pos 位置插入
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

Node *Search_pre(List plist,int key)//查找 key 的前驱
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

bool Delete(List plist,int key)//删除 key 这个结点
{
	Node *p = Search_pre(plist,key);
	if(p == NULL)
	{
		return false;
	}
	Node *pDel = p->next;//删除的节点
	p->next = pDel->next;
	free(pDel);
	pDel = NULL;
	return true;
}

bool IsEmpty(List plist)//是否为空
{
	if(plist == NULL || plist->next == NULL)
	{
		return true;
	}
	return false;
}

void Destroy(List plist)//摧毁函数（如果有动态开辟内存）
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
//得到单链表的长度
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

//打印单链表
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