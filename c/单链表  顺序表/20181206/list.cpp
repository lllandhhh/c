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
Node *FindEnte(List plist)//找 环的入口点 
{
	Node *p1 = plist;
	Node *p2 = plist;
	int m = 0;//环的长度
	while (p1 != p2)
	{
		p1 = p1->next;
		p2 = p2->next->next;
	}
	p1 = p1->next;
	while (p1 != p2)
	{
		p1 = p1->next;
		m++;
	}
	p1 = plist;
	while (p1 != p2)
	{
		p1 = p1->next;
		p2 = p2->next->next;
	}
	return p2->next;
}
Node* MergeList(List plist1, List plist2)//合并单链表
{
	Node *p1 = plist1->next;
	Node *p2 = plist2->next;
	Node *newHead = NULL;//合并后的链表的 头节点
	if (p1->data < p2->data)
	{
		newHead = plist1;
	}
	else
	{
		newHead = plist2;
	}
	Node *tmpnewHead = newHead;
	while (p1 != NULL&&p2 != NULL)
	{
		if (p1->data < p2->data)
		{
			tmpnewHead->next=p1;
			p1 = p1->next;
		}
		else
		{ 
			tmpnewHead->next = p2;
			p2 = p2->next;
		}
		tmpnewHead = tmpnewHead->next;
	}
	if( p1!= NULL)
	{
		tmpnewHead ->next= p1;
	}
	if ( p2 != NULL)
	{
		tmpnewHead ->next= p2;
		}

	return newHead;
}
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

bool Insert_head(List plist,int val)//头插法
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
	Node *cur = GetNode(val);
	Node *dur = plist;//指向头结点  依赖前驱信息的
	int m = 0;
	while (m<pos)
	{
		dur = dur->next;
		m++;
	}
	cur->next = dur->next;
	dur->next = cur;
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

bool Delete(List plist, int key)//删除 key 这个结点
{
	Node *cur = plist;
	while (cur->next != NULL)
	{
		if (cur->data == key-1)
		{
			cur->next= cur->next ->next;
			break;
		}
		else cur = cur->next;
	}
	return false;
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
	Node *pDel=NULL;
	while (plist->next!=NULL)
	{
		pDel = plist->next;
		plist->next = pDel->next;
		free(pDel);
	}
	pDel = NULL;

}

int GetLength(List plist)//得到单链表的长度
{
	Node *cur = plist;//指向头结点  依赖前驱信息的
	int m = 0;
	while (cur->next != NULL)
	{
		cur = cur->next;
		m++;
	}

	printf("%d", m);
	return 0;
}
void Show(List plist)//打印单链表
{
	Node *cur = plist;//指向头结点  依赖前驱信息的
	while (cur->next!= NULL)
	{
		cur = cur->next;
		printf("%d", cur->data);
	}

}
void fanzhuan(List plist)
{

}
void nizhi(List plist)
{
	Node *cur = plist->next;
	plist->next=NULL;
	while (cur != NULL)
	{
		Node *curnext = cur->next;
		cur->next = plist->next;
		plist->next = cur;
		cur =curnext;
		
	}
	Node *cu = plist;//指向头结点  依赖前驱信息的
	int  i=0;
	while (i<10)
	{
		cu = cu->next;
		i++;
		printf("%d", cu->data);
	}
}
Node *ListK(List plist, int k)
{
	Node *p = plist;
	for (int i = 0;i < k;i++)
	{
		plist = plist->next;
	}
	Node *P1 = plist;
	while (P1 ->next!= NULL)
	{
		P1 = P1->next;
		p = p->next;
	}
	printf("%d", p->data);
	return p;
}
void dlist(List plist, int k)
{
	Node *p = plist;
	for (int i = 0;i < k+1;i++)
	{
		plist = plist->next;
	}
	Node *P1 = plist;
	while (P1 ->next!= NULL)
	{
		P1 = P1->next;
		p = p->next;
	}
	Node *P2 = p->next;
	p->next= P2->next;
	free(P2);
}
bool lscut(List plist1, List plist2)//判断两个单链表 是否相交
{
	Node *p1 = plist1;
	Node *p2 = plist2;
	int m = 0;
	while (p1->next != NULL)
	{
		p1 = p1->next;
		m++;
	}
	int n= 0;
	while (p2->next != NULL)
	{
		p2 = p2->next;
		n++;
	}
	int c = m - n;
	p1 = plist1;
	p2 = plist2;
	for (int i = 0;i < c;i++)
	{
		p1 = p1->next;
	}
	while (p2->next != NULL)
	{
		if (p2->next == p1->next)
		{
			printf("%d", p2->data);
			break;
		}
		p2 = p2->next;
		p1 = p1->next;
	}
	return true;
}