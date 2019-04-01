#include<stdio.h>
#include<string>
#include <stdlib.h>
//
//int substr(char dst[], char src[], int start, int len)
//{
//	int m = 0;
//	src = (char *)malloc(sizeof(char) * (len));
//	for (int i = start ;i < start+len;i++)
//	{
//		src[m] = dst[i];
//		m++;
//	}
//	
//	src[m] = '\0';
//	int i = 0;
//
//	while (src[i]!='\0')
//	{
//		printf("%c", src[i]);
//		i++;
//	}
//	return m;
//}
//int main()
//{
//	char *a = "abddadyhffh";
//	char *b = "00" ;
//	int n = substr(a, b, 2, 5);
//	printf("%d", n);
//	getchar();
//	return 0;
//}
void deblank(char string[])
{
	int i = 0;
	int m = strlen(string);
	char *arr;
	arr = (char *)malloc(sizeof(char) * (m));
	while (string[i]!= '\0')
	{
		arr[i] = string[i];
		i++;
	}
 i = 1;
	while (arr[i]!= '\0')
	{
		if (arr[i-1] == ' '&&arr[i] == ' ')
		{
			int n = i;
			for (n;n <m-1 ;n++)
			{
				arr[n] = arr[n + 1];
				
			}
			m--;
		}
		else i++;
	}
	for (int n=0;n < m;n++)
	{
		printf("%c", arr[n]);
	}
}

int main()
{
	char *a = "12  3 4       56";
	deblank(a);
	getchar();
	return 0;
}
1.左数第 bit 位置 1
2.左数第 bit 位置 0
3.获取第 bit 位的值

1.n= n|( 1 <<bit)
2.n = n&~(1 <<bit));
3.n = (n >>bit)) & 1;