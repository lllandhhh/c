#include<stdio.h>
#include"link.h"
#include<stdlib.h>
void InitList(List plist)//初始化单链表
{
	plist->next = NULL;
}
static Node  *GetNode(int val)
{
	Node * pGet = (Node *)malloc(sizeof(Node));
	pGet->data = val;
	pGet->next = NULL;
}
bool Insert_head(List plist, int val)//头插法
{
	Node * pGet = GetNode(val);
	pGet->next = plist->next;
	plist->next = pGet;
	return true;
}

bool Insert_tail(List plist, int val)//尾插法
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
bool Insert_pos(List plist, int pos, int val);//pos 位置插入                                                                                作业

Node *Search_pre(List plist, int key)//查找 key 的前驱==地址
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
bool Delete(List plist, int key);//删除 key 这个结点

bool IsEmpty(List plist);//是否为空

void Destroy(List plist);//摧毁函数（如果有动态开辟内存）

int GetLength(List plist);//得到单链表的长度

void Show(List plist);//打印单链表
