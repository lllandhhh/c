//11.
//#include<stdio.h>
//void ReboundBall()
//{
//	int i = 1;float n = 100;float q = 100;float m = 0;
// 	for(i;i<=10;i++)
//	{
//		n = n / 2;
//	}
//	for (i = 1;i<10;i++)
//	{
//		q = q / 2;
//		m = m + 2 * q;
//	}
//	printf("%lf %lf",n,m+100);
//}
//int main()
//{
//	ReboundBall();
//	getchar();
//	return 0;
//}
//
////12.
//#include<stdio.h>
//void peach()
//{
//	float n = 0;
//	float i = 10;
//	for (i;;i++)
//	{
//		n = i;int m =1;
//		for (m;m <10;m++)
//		{
//			n= n/2-1;
//			if (n < 0)break;
//		}
//		if (n == 1)
//			break;
//	}
//	printf("%lf", i);
//}
//int main()
//{
//	peach();
//	getchar();
//	return 0;
//
//}
#include<stdio.h>
int number(int* p, int m)
{

	int i = 0;int j = 0;int q = 0;;
	for (i;i < m;i++)
	{
		j = i;
		if (p[j] % 2 == 0) 
		{q++;
			for (j;j <m-1;j++)
			{
				p[j] = p[j + 1];
			}
		}
	}
	return (5-q);
}
int main()
{
	int m = 0;
	int i=0;
	int a[5] = { 1,2,3,4,5 };
	int *p = a;
	m=number(p,5);
	for (i; i <m;i++)
		printf_s("%d", m);	
	getchar();
	return 0;
	
}