#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>
typedef struct Word
{
	char arr[10];
	int count;//��ǰ�õ��ʸ���
}Word;
typedef struct Num
{
	Word brr[100000];//ָ�򵥴ʵ�ָ��
	int length;
	int listsize;
}N;//�ܵ��ʸ���
void CopyMp4(const char* srcpath)
{
	N y;

	char *str = (char*)malloc(sizeof(int) * 1000000);
	FILE *fr = fopen(srcpath, "r");
	char ch;int n = 0;
	while (fread(&ch, sizeof(char), 1, fr) > 0)//��ȡ�ַ��ĸ���
	{

		str[n] = ch;
		n++;//��ӡ�ַ�  ���ỻ��
	}
	////int i;
	////for (i = 0;i <= n;i++) 
	////{
	////	putchar(str[i]);
	////}
	char *p = (char*)malloc(sizeof(int) * n);char *q = (char*)malloc(sizeof(int) * n);p = str;q = str;
	int i;int m = 0;
	for (i = 0;i <= n;i++)
	{
		if (p[i] == ' '&&q[i + 1] != ' ' || (p[i] == ' '&&q[i+1]!= ' '))
			m++;
	}
	printf("���ٵ���%d",m);
	/*y.brr = (Word *)malloc(sizeof(int) * m);*/
	int num = 0;
	int j = 0;
	p = str; q = str + 1;int t = 0;int d = 0; i = 0;
	while (*q!= '\0')
	{
		if ((*p !=' '&&*q!= ' '))
		{
			t++;d = 0;
			while (*p!= ' ')
			{
				y.brr[t].arr[d] = *p;
				y.brr[t].count = 0;
				p++;
				d++;
			}
			q = p;
		}
		q++;p++;
	}
	for (i = 0;i <= m;i++)
		for (j = 0;j<40;j++)
		{
			printf("%c", y.brr[i].arr[j]);
		}
	free(str);
	free(p);
	free(q);
	free(y.brr);
}
int main()
{
	char *srcpath = "C:\\Users\\rmk\\Desktop\\1.txt";
	CopyMp4(srcpath);
	system("pause");
	return 0;
}