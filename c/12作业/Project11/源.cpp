#include<stdio.h>
#include<string.h>
#include <stdlib.h>
//int majorityElement(int* nums, int numsSize)//����
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
int missingNumber(int* nums, int numsSize)//  ��ȱʧ���Ǹ���
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
//3�����������Ƶ��ַ����Ƚ�/
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
	printf("��%d��ͬ",m);
	return 0;
}
//4�������ַ� ch���ڸ����ַ������ֵ����һ��
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
//5���ַ������Ҹ����ַ����� n �γ��ֵ�λ��
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
//6�����ҵ�һ���������棬�ж��ٸ��ַ���ڶ���ƥ�䣬˳���޹ء�
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
//8����λ����
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
////10�������������Ĵ��������������ַ����е��ַ���*���Ƶ��ַ�����ǰ���֣�
////ǰ��ķǡ�*���ַ����ƣ����ǲ��ܸı�ǡ�*���ַ����Ⱥ�˳��, ���������ַ����зǡ�*���ַ���������
////���磺ԭʼ��ΪTu**lu**n**ba*by, �����Ϊ*******Tulunbaby��������9.
////����ԭ�ͣ�void ChangStr(char *str)��
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