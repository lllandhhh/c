#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#define M 500000
typedef struct Word
{
	char arr[40];
	int count;//当前该单词个数
	int nn;
}Word;
typedef struct Num
{
	Word *brr;//指向单词的指针
	int length;
	int listsize;
}N;//总单词个数
void CopyMp4(const char* srcpath)
{
	N y;
	FILE *fr = fopen(srcpath, "r");
	char ch;
	int n = 0;
	char *str = (char*)malloc(sizeof(char) * M);
	while (fread(&ch, sizeof(char), 1, fr) > 0)//读取字符的个数
	{

		str[n] = ch;
		n++;//打印字符  不会换行
	}
	int i = 0;
	/*	for (i = 0;i <= n;i++)
	{
		cout<<str[i]<<endl;
	}*/
	char *p;
	char *q;
	p = str;q = str;
	int m = 0;
	for (i = 0;i <= n;i++)
	{
		if (p[i] == ' '&&q[i + 1] != ' ')
			m++;
	}
	printf("多少单词%d\n", m);
	y.brr = (Word *)malloc(sizeof(Word) * m);
	i = 0;
	int j = 0;
	p = str;
	q = str + 1;
	while (i < m - 1)
	{
		if (*p == ' '&&*q != ' ')
		{
			j = 0;
			while (*q != ' ')
			{
				if(!ispunct(*q))
				{
				y.brr[i].arr[j] = *q;
				q++;
				j++;
			    }
				else q++;
			}
			y.brr[i].count = j;
			i++;
			p = q;
			q++;
		}
		else
		{
			p++;q++;
		}
	}
	int k = 0;int l = 0;int mun = 0; n = 0;
	for (i = 0;i < m;i++)
	{
		if (y.brr[i].count == 0) continue;
		n = 0;y.brr[i].nn = 0;
		for (j = i+1;j < m;j++)
		{
			if (y.brr[i].count == y.brr[j].count)
			{
				mun = 0;
				for (k = 0;k < y.brr[i].count;k++)
				{
					if (y.brr[i].arr[k] == y.brr[j].arr[k])
					{
						mun++;
					}
				}
				if (mun == y.brr[j].count)
				{
					n++;
					y.brr[j].count=0;
					y.brr[i].nn = n;
				}
			}
		}
	}
	/*k = 0;n = 1;int t = 1;l = 0;
	for (i = 0;i < m;i++)
	{
		for (j = 0;j < m-1;j++)
		{
			n = 1;
			if (y.brr[j].count == 0) continue;
			while (y.brr[j + n].count == 0)
				n++;
			if (y.brr[j].nn < y.brr[j + n].nn)
			{
				char b = 0;int p = 0;
				p = y.brr[j].nn;
				y.brr[j].nn = y.brr[j + n].nn;
				y.brr[j + n].nn = p;
				for (k = 0;k < 10;k++)
				{
					b = y.brr[j].arr[k];
					y.brr[j].arr[k] = y.brr[j + n].arr[k];
					y.brr[j + n].arr[k] = b;
				}
			}j = j + n;
		}

	}*/
n = 5000;
	while (n>=0)
	{
			for (i = 0;i < m;i++)
			{
				if (y.brr[i].nn == n)
				{
					for (j = 0;j < y.brr[i].count;j++)
					{
						printf("%c", y.brr[i].arr[j]);
					}
					printf("  %d\n", y.brr[i].nn);
				}
			}
			n--;
	}
	/*for (i = 0;i < m;i++)
	{
		if (y.brr[i].count == 0) continue;
		for (j = 0;j < y.brr[i].count;j++)
		{
			cout << y.brr[i].arr[j];
		}
		cout << " "<<y.brr[i].nn;
		cout << endl;
	}*/
}

int main()
{
	char *srcpath = "C:\\Users\\rmk\\Desktop\\1.txt";
	CopyMp4(srcpath);
	system("pause");
	return 0;
}
