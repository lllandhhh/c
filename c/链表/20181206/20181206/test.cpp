#include<stdio.h>
//#include"sqlist.h"
//#include"Dsqlist.h"
#include"list.h"
#include<stdlib.h>
#include<vld.h>
#include<assert.h>
Node* Reverse1(List plist)//反转
{
	Node *prev = NULL;
	Node *reverHead = NULL;
	Node *cur = plist;
	while(cur != NULL)
	{
		Node *curNext = cur->next;
		if(curNext == NULL)
		{
			reverHead = cur;
		}
		cur->next = prev;//NULL
		prev = cur;
		cur = curNext;
	}
	return reverHead;
}

void Show2(Node *reverHead)
{
	Node *p = reverHead;
	while(p->next != NULL)
	{
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}
void Reverse2(List plist)//头插法逆置
{
	Node *cur = plist->next;
	plist->next = NULL;
	while(cur != NULL)
	{
		Node *curNext = cur->next;
		cur->next = plist->next;
		plist->next = cur;
		cur = curNext;
	}
}
//最快时间内找到单链表倒数第K个节点？
Node *LastK(List plist,int k)
{
	if(k < 0 || plist == NULL)
	{
		return NULL;
	}
	Node *p1 = plist;
	Node *p2 = plist;
	while(k-1 > 0)
	{
		if(p1->next != NULL) 
		{
			p1 = p1->next;
			--k;
		}
		else
		{
			return NULL;
		}
	}
	while(p1->next != NULL)
	{
		p1 = p1->next;
		p2 = p2->next;
	}
	return p2;
}
//最快时间内删除单链表倒数第K个节点？CVTE
void DeleteLastK(List plist,int k)
{
	if(k < 0 || plist == NULL)
	{
		return ;
	}
	Node *p1 = plist;
	Node *p2 = plist;
	while(k > 0)
	{
		if(p1->next != NULL) 
		{
			p1 = p1->next;
			--k;
		}
		else
		{
			return;
		}
	}
	while(p1->next != NULL)
	{
		p1 = p1->next;
		p2 = p2->next;
	}
	Node *pDel = p2->next;
	p2->next = pDel->next;
	free(pDel);
	pDel = NULL;
}
//O(1)时间删除单链表的一个节点   百度
//del==>删除的节点
void DeleteNode(List plist,Node *pDel)
{
	assert(plist != NULL && pDel != NULL);
	if(pDel->next != NULL)
	{
		Node *pDelNext = pDel->next;
		pDel->data = pDelNext->data;
		pDel->next = pDelNext->next;
		free(pDelNext);
	}
	else
	{
		Node *pCur = plist;
		while(pCur->next != pDel)
		{
			pCur =pCur->next;
		}
		pCur->next = NULL;
		free(pDel);
	}
}

//判断两个单链表是否相交？交点？
void CreateCut(List plist1,List plist2)
{
	plist1->next->next = plist2->next->next->next;
}

bool IsCut(List plist1,List plist2)
{
	int len1 = GetLength(plist1);
	int len2 = GetLength(plist2);
	Node *plong = plist1;
	Node *pshort = plist2;
	int len = len1-len2;
	if(len < 0) 
	{
		plong = plist2;
		pshort = plist1;
		len = len2-len1;
	}
	//plong肯定指向长的   pshort 
	//len > 0
	for(int i = 0;i < len;i++)
	{
		plong = plong->next;
	}
	while(plong != NULL && pshort != NULL && plong != pshort)
	{
		plong = plong->next;
		pshort = pshort->next;
	}
	if(plong == pshort && plong != NULL)
	{
		return true;
	}
	return false;
}

Node* IsCutNode(List plist1,List plist2)
{
	int len1 = GetLength(plist1);
	int len2 = GetLength(plist2);
	Node *plong = plist1;
	Node *pshort = plist2;
	int len = len1-len2;
	if(len < 0) 
	{
		plong = plist2;
		pshort = plist1;
		len = len2-len1;
	}
	//plong肯定指向长的   pshort 
	//len > 0
	for(int i = 0;i < len;i++)
	{
		plong = plong->next;
	}
	while(plong != NULL && pshort != NULL && plong != pshort)
	{
		plong = plong->next;
		pshort = pshort->next;
	}
	if(plong == pshort && plong != NULL)
	{
		return plong;
	}
	return NULL;
}




int  main()
{
	Node head;//头结点
	InitList(&head);
	for(int i = 0; i < 10;i++)
	{
		Insert_head(&head,i);
	}
	Show(&head);

	Node head2;//头结点
	InitList(&head2);
	for(int i = 10; i < 30;i++)
	{
		Insert_head(&head2,i);
	}
	Show(&head2);
	CreateCut(&head,&head2);
	Show(&head);
	Show(&head2);
	if(IsCut(&head,&head2))
	{
		
		Node *p = IsCutNode(&head,&head2);
		printf("is  cut ! %d\n",p->data);
	}
	else
	{
		printf("is not cut!\n");
	}


	return 0;
}

#if 0
int main()
{
	Node head;//头结点
	InitList(&head);
	/*for(int i = 0; i < 10;i++)
	{
		Insert_head(&head,i);
	}*/
	Insert_head(&head,1);
	Insert_head(&head,2);
	Show(&head);
	DeleteNode(&head,head.next->next);
	Show(&head);
	Destroy(&head);
	/*Show(&head);
	Node *p = LastK(&head,3);
	printf("%d\n",p->data);
	DeleteLastK(&head,-1);
	Show(&head);*/
	/*Reverse2(&head);
	Show(&head);*/
	//Show2(Reverse1(&head));
	/*Insert_pos(&head,3,99);
	Show(&head);
	Delete(&head,5);
	Show(&head);
	int len = GetLength(&head);
	printf("len == %d\n",len);
	Destroy(&head);*/
	return 0;
}


/*
求两个顺序表的交集   并集   新的顺序表里面
1,2,3,4,5,6     3，4, 8
*/
int main()
{
	DSqlist ds;
	InitList(&ds);
	for(int i = 0;i < 20;i++)
	{
		Insert(&ds,i,i);	
	}
	Show(&ds);
	Delete(&ds,0,0);
	Show(&ds);
	Destroy(&ds);
	return 0;
}

//int main()
//{
//	Sqlist sq;
//	InitSqlist(&sq);
//	Sqlist sq2;
//	InitSqlist(&sq2);
//	/*Insert(&sq,0,1);
//	Insert(&sq,1,2);*/
//	for(int i = 0;i < 20;i++)
//	{
//		Insert(&sq,i,i);	
//	}
//	Show(&sq);
//	Delete(&sq,0,0);
//	Show(&sq);
//	return 0;
//}
#endif