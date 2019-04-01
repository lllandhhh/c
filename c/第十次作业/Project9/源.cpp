//算法题：求一个有序数组中两个值相加为k的数字，返回这两个数字的下标。
//#include<stdio.h>
//int Add(int a[6], int m, int n)
//{
//	int k = 0;
//	m = m - 1;
//	while (k<= m)
//	{
//		if (a[k] + a[m]>n)m--;
//		if (a[k] + a[m] < n)k++;	
//		if(a[k] + a[m]==n)
//		{
//			printf("%d%d", k, m);
//			break;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	int a[6] = { 1,2,3,4,5,6 };
//Add(a,6,9);
//getchar();
//return 0;
//
//}
//(40   )41   123 {    125}

//#include<stdio.h>
//#include<string.h>
//int Kuohao(char *a)
//{
//	int m;
//	m = strlen(a)-1;
//	int i;
//	int n;
//	n = m;
//	for ( i = 0;i<=(n/2);i++)
//	{
//			if ((a[i] == 40 && a[m] == 41)||(a[i] == 123 && a[m] == 125))
//			{
//				m--;
//			}
//			else 
//
//		 { printf("括号不匹配"); return 0; }
//	
//	}
//	printf("括号匹配");
//	return 0;
//}
//int main()
//{
//	char *a="{}{}{}";
//	Kuohao(a);
//	getchar();
//	return 0;
//}