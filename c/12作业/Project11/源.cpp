#include<stdio.h>
#include<string.h>
#include <stdlib.h>
//int majorityElement(int* nums, int numsSize)//众数
//{
//int m = numsSize / 2;
//int i = 0;
//int add = 0;
//for (i = numsSize - 1;i >= 0;i--)
//{
//	add = 0;
//	int j;
//	for (j = numsSize - 1;j >= 0;j--)
//	{
//		if (nums[i] == nums[j])
//		{
//			add = add + 1;
//			if (add > m)
//			{
//				return nums[i];
//			}
//		}
//
//
//	}
//}
//return 0;
//}

//
//
//	int main()
//	{
//		int a[3] = { 3,2,3 };
//		majorityElement(a, 3);
//		getchar();
//		return 0;
//
//	}
//
//
int missingNumber(int* nums, int numsSize)//  求缺失的那个数
{
	int m = 0;int j = 0;
	for (int i = 0;i<numsSize;i++)
	{
		m = m^j^nums[i];
		j++;
	}
	m = m^j;
	return m;
}
//1.
char *My_strcnpy(char *des, const char *src, int n)
{
	for (int i = 0;i < n;i++)
	{
		des[i] = src[i];
	}
	return 0;
}
//2.
char *My_strncat(char *des, const char *str, int n)
{
	int m = strlen(des);
	 n = strlen(str);
	for (int i=0;i<=n;i++)
	{
		des[i+m] = str[i];
	}
	return 0;
}
//3、长度受限制的字符串比较/
int My_strcnmpy(const char *str1, const char *str2, int n)
{
	int m=0;
	for (int i = 0;i < n;i++)
	{
		if (str1[i] == str2[i])
		{
			m++;
		}
	}
	printf("有%d相同",m);
	return 0;
}
//4、查找字符 ch，在给定字符串出现的最后一次
char *my_strrchr(const char *str,int ch)
{
	int m = strlen(str);
	for (int i = m - 1;i>= 0;i--)
	{
		if ( str[i] == ch) 
		{
			printf("%d",i); break;
		}
	}
	return 0;
}
//5、字符串查找给定字符，第 n 次出现的位置
char *my_strnchr(const char *str, char ch, int n)
{
	int m = strlen(str);int l = 0;
	for (int i = 0;i<m;i++)
	{
		if (str[i] == ch)
			l++;
		if (l = n)
			printf("%d", i);
	}
	return 0;
}
//6、查找第一个参数里面，有多少个字符与第二个匹配，顺序无关。
int Count_chars(const char *str, const char *chars)
{
	int m = strlen(str);
	int n= strlen(chars);
	int l = 0;
	for (int i = 0;i < m;i++)
	{
		for (int j = 0;j < n;j++)
		{
			if (str[i] == str[j])l++;break;
		}
	}
	printf("%d", l);
	return 0;
}
//8、单位矩阵
int danwei(int n)
{
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++)
		{
			if (i == j)printf("%d", 1);
			else printf("%d", 0);
		}
		printf("\n");
	}
	return 0;
}
char cp(char str[])
{
	int m = strlen(str);
	for (int i = 0;i < m;i++)
	{
		if (str[i] == ' ')str[i] = '#';
	}
	return 0;
}
////10、编码完成下面的处理函数，函数将字符串中的字符’*’移到字符串的前部分，
////前面的非’*’字符后移，但是不能改变非’*’字符的先后顺序, 函数返回字符串中非’*’字符的数量。
////例如：原始串为Tu**lu**n**ba*by, 处理后为*******Tulunbaby函数返回9.
////函数原型：void ChangStr(char *str)；
void ChangStr(char *str)
{
	char *a;
	int m = strlen(str);
	a = (char *)malloc(sizeof(char)*m);
	int j = 0;
	for (int i = 0;i < m;i++)
	{
		if (str[i] == '*')a[j++] = str[i];
	}
	for (int i = 0;i < m;i++)
	{
		if (str[i] != '*')a[j++] = str[i];
	}
	a[j] = '\0';
	printf("%s", a);
}

int main()
{
	char a[] = "12****345***6";
	char b[] = "ab   c     de";
	int n[6] = { 0,1,2,3,4,6 };
	printf("%d",missingNumber(n,6));
	//My_strcnpy(b,a , 10);
	//My_strncat(b,a,0);
	//My_strcnmpy(b, a, 6);
	//my_strrchr(b,'d');
	//cp(b);
	/*ChangStr(a);

	printf("%s",b);*/
	/*danwei(5);*/
	getchar();
	return 0;
}