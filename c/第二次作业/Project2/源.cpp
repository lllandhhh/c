//3.
////#include<stdio.h>
////int main()
////{
////	int x, y, i, m, n;
////	printf_s("请输入两个数：");
////	scanf_s("%d%d", &x, &y);
////	m = x, n = y;
////	for (i = x; i > 0; i--)
////	{
////		if (x%i == 0 && y%i == 0)
////			break;
////	}
////	printf_s("最大公约数是: %d\n", i);
////	printf_s("最小公倍数是: %d\n", m*n / i);
////	scanf_s("%d%d", &x, &y);
////	return 0;
////}
//5.
//#include<stdio.h>
//void Add(int m,int n)
//{
//	int i=0;int a=m;
//	int sum=0;
//	for (i=0;i<n;i++)
//	{
//		sum = sum + m;
//		m = m*10+a;
//	}
//	printf_s("%d", sum);
//}
//int main()
//{
//	int a=0 ;
//	int b = 0;
//	scanf_s("%d%d", &a,&b);
//	Add(a, b);
//	scanf_s("%d%d", &a, &b);
//	return 0;
//}
//8.
//#include<stdio.h>
//#include< math.h>
//void Power()
//
//{
//	int a = 0;
//	int i = 0;
//	for (i = 100;i<1000;i++)
//	{
//		a = i;
//		if (i == pow((a/100), 3) + pow(((a%100)/10), 3) + pow(((a % 100) % 10), 3))
//			printf_s("%d\n", i);
//	}
//}
//int main()
//{
//	Power();
//	int a;
//	scanf_s("%d", &a);
//	return 0;
//}
//9.
//#include<stdio.h>
//void PerfectNumber()
//{
//	int i = 1;int j = 0;
//	
//	for (i = 1;i <= 1000;i++)
//	{
//		int a[100];int b = 0;int sum = 0;
//		for (j=1;j<i;j++)
//		{
//			if (i%j == 0)
//			{
//				sum += j;
//				a[b] = j;
//				b++;
//			}
//		}
//		if (sum == i)
//		{
//			printf("%d its factors are ", i);
//			for (j = 0;j < b;j++)
//			{
//				printf("%d ", a[j]);
//				
//			}
//			printf("\n");
//		}
//	}
//}
//int main()
//{
//	PerfectNumber();
//	int a;
//	scanf_s("%d", &a);
//	return 0;
//}
//10
//#include <stdio.h>
//void main()
//{
//	double sum = 0, x = 2, y = 1, i = 0, j = 0;
//	for (i = 0;i < 20;i++)
//	{
//		sum = sum + (x/y);
//		j = x;
//		x = x + y;
//		y = j;
//	}
//	printf("前20项和为%lf",sum);
//	int a;
//scanf_s("%d", &a);
//}
//3.
//#include<iostream>
//using namespace std;
//int main()
//{
// int i=0;
// int p;
// cout << "计算多少项" << endl;
// cin >> p;
// int m = 1;int n = 1;int q=0;
// int a[100];
// for (i = 0;i <p;i++)
// {
//  m= q;
// q = m + n;
// n = m;
// cout << q << endl;
// a[i] = q;
// }
// cin >> i;
// return 0;
//}
//#include<iostream>
//using namespace std;
//int Max(int A[], int N)
//{
//	int ThisSum = 0, MaxSum = 0, i, j, k;
//	for (i = 0;i < N;i++)
//	{
//		for (j = i;j < N;j++)
//		{
//			ThisSum = 0;
//			for (k = i;k <= j;k++)
//				ThisSum += A[k];
//
//			if (ThisSum > MaxSum)
//				MaxSum = ThisSum;
//		}
//	}
//	cout <<MaxSum<< endl;
//	return 0;
//}
//int main()
//{
//	int A[20];
//	int i;
//	int n;
//	cin >> n;
//	int* p = A;
//	for (i = 0;i < n;i++)
//		cin >> p[i];
//	Max(p, n);
//	cin >> n;
//	return 0;
//}