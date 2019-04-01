//1、用联合体判断大小端？？
//2、第九章第一题？
//3、在第一个字符串中 ，删除第二个字符串中所有的字符。
//函数原型：char *DeleteChars(char *str1, char *str2);
//参数str1:"Welcome Tulun"   参数str2 : "come"    结果输出 : "Wl Tulun"
//	4、筛选法求100以内的素数。
//	* /
#include<stdio.h>
#include <stdlib.h>
//1.
//	union u1
//	{
//		char arr;
//		int n;
//	
//
//	}a;

//2.

//struct Year
//{
//	int day;
//	int month;
//	int year;
//}a;
//void Day(struct Year a)
//{
//	int i;
//	int add = 0;
//	int b[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//	if (a.year % 4 == 0 && a.year  % 100 != 0 || a.year  % 400 == 0)
//	{
//		for (i = 0;i < a.month-1;i++)
//			add = add+b[i];
//		add = add + a.day;
//	}
//	else {
//		for (i = 0;i < a.month-1;i++)
//			add = add + b[i];
//		add = add + 1+a.day;
//	}
//	printf("%d", add);
//}
//4.
//void sushu(int a[100])
//{
//	int i, j;
//
//	for (i = 0;i < 100;i++)
//	{
//		a[i] = i + 1;
//	}
//
//	a[0] = 0;
//	for (i = 0;i < 99;i++)
//	{
//		for (j = i + 1;j < 100;j++)
//		{
//			if (a[i] != 0 && a[j] != 0)
//			{
//				if (a[j] % a[i] == 0)
//				{
//					a[j] = 0;
//				}
//			}
//		}
//	}
//
//	for (i = 0;i < 100;i++)
//	{
//		if (a[i] != 0)
//		{
//			printf("%d\n", a[i]);
//		}
//	}
//}
//int main()
//{
//	int a[100];
//	sushu(a);
//	//a.n =  0X12345678 ;
//	//printf("%x", a.arr);// 低地址高字节  为大端
//	/*	a = { 2,3,1996 };
//	Day(a);*/
//	system("pause");
//	return 0;
//}
//
//S1: welcome tulun == == = >wl tulun
//	S2 : come
//#include<iostream>
//using namespace std;
//void xiaocu(char *str, char *ste)
//{
//	char*m = str;
//	char*n = ste;
//	while (*n != '\0')
//	{
//		m = str;
//		while (*m != '\0')
//		{
//			if (*m == *n)
//			{
//				*m ='0';
//			}
//			m++;
//		}
//		n++;
//	}
//	m = str;
//		while (*m!= '\0')
//	{
//		if (*m!='0')
//			cout << *m;
//		 m++;
//	}
//}
//int main()
//{
//	char a[] = " welcome tulun";
//	char b[] = "come";
//	xiaocu(a, b);
//	int i;
//	cin >> i;
//	return 0;
//}