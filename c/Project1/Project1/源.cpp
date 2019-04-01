//1、用联合体判断大小端？？
//2、第九章第一题？
//3、在第一个字符串中 ，删除第二个字符串中所有的字符。
//函数原型：char *DeleteChars(char *str1, char *str2);
//参数str1:"Welcome Tulun"   参数str2 : "come"    结果输出 : "Wl Tulun"
//	4、筛选法求100以内的素数。
//	* /
#include<stdio.h>
#include <stdlib.h>
//	union u1
//	{
//		char arr;
//		int n;
//	
//
//	}a;
//
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
void sushu(int a[100])
{
	int i = 0;
	int m=1;
	for (i = 0;i < 101;i++)
	{
		a[i] = m++;
	}
	int b[100];
	int n=1;
	b[0] = 2;
	for (i = 2;i < 101;i++)
	{
		if (a[i] % 2!= 0)
		{
			b[n] = a[i];
			n++;
		}
	}
	n = 0;
	while (b[n] != '\0')
	{
		for (i = 1;i < 101;i++)
		{
			if (a[i] % b[n] == 0)
			{
				a[i] = 0;
			}
			if (i = 100)
			{
				n++;
				i = 0;
			}
		}
	}
	for (i = 0;i < 101;i++)
	{
		printf("%d\n", a[i]);
	}
}
	int main()
	{
		int a[100];
		sushu(a);
	//a.n =  0X12345678 ;
	//printf("%x", a.arr);// 低地址高字节  为大端
	/*	a = { 2,3,1996 };
		Day(a);*/
	system("pause");
	return 0;
}
