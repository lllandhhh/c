//<= 4字节 通过寄存器带出来
//>4 <= 8 字节 通过两个寄存器带出来
//>8 字节 通过产生临时量，此时返回值太大，寄存器已经没有足够的内存存放它
//#include<stdio.h>
//#include <stdlib.h>
//int Feibo(int n)
//{
//	int sum;int add;
//	if (n == 1)
//		return 1;
//	if (n == 2)
//		return 1;
//	return Feibo(n - 1) + Feibo(n-2);
//}
//int main()
//{
//	printf("%d",Feibo(5));
//	system("pause");
//	return 0;
//	
//}
//#include<stdio.h>
//#include <stdlib.h>
//int Erfen(int a[],int low,int higt,int number )
//{
//	int c = (low + higt) / 2;
//	if (a[c] == number)
//		return c;
//	if (a[c] > number)
//		return Erfen(a, low, c - 1, number);
//	if (a[c] < number)
//		return Erfen(a, c + 1, higt, number);
//
//}
//int main()
//{
//	int a[10] = { 0,1,2,3,4,5,6,7,8,9 };
//	printf("%d", Erfen(a, 0, 10, 9));
//	system("pause");
//	return 0;
//}
#include<stdio.h>
#include <stdlib.h>
void hanoi(int n, char a, char b, char c)
{
	if (n == 1)
		printf("%d%c->%c\n",n,a, c);
	else
	{
		hanoi(n - 1, a, c, b);
		printf("%d%c->%c\n",n, a, c);
		hanoi(n - 1, b,a, c);
	}
	
}
int main()
{
	hanoi(3, 'A', 'B', 'C');
	system("pause");
	return 0;

}