#include<stdio.h>
//#include"sqlist.h"
//#include"Dsqlist.h"
#include <vld.h>
#include"list.h"
#include"clist.h"
/*
求两个顺序表的交集   并集   新的顺序表里面
1,2,3,4,5,6     3，4, 8
*/
//int main()//顺序表
//{
//	DSqlist ds;
//	InitList(&ds);
//	for(int i = 0;i < 20;i++)
//	{
//		Insert(&ds,i,i);	
//	}
//	Show(&ds);
//	Delete(&ds,0,0);
//	Show(&ds);
//	Destroy(&ds);
//	return 0;
//}

//int main()//单链表
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
//int main()
//{
//	Node q;
//	InitList(&q);
//	Node q0;
//	InitList(&q0);
//	for (int i = 0;i < 10;i++)
//	{
//		Insert_head(&q,i);
//	}
//	for (int i = 0;i < 5;i++)
//	{
//		Insert_head(&q0, i);
//
//	}
//	//Delete(&q, 3);
//	//GetLength(&q);
//	//ListK(&q,3 );
//	//Destroy(&q);
//	//dlist(&q, 0);
//	Show(MergeList(&q, &q0));
//	getchar();
//	getchar();
//		return 0;
//}
int main()//循环链表
{
	CNode q;
	InitList(&q);
	for (int i = 0;i < 10;i++)
	{
		Insert_head(&q,i);//头插法
		//Insert_tail(&q, i);//尾插法
	}
	Show(&q);
	getchar();
	getchar();
	return 0;
}