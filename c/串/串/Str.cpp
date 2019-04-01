#include"Str.h"
#include<assert.h>
#include<stdio.h>
#include<string.h>
typedef struct Str
{
	char elem[SIZE];
	int length;//�ڴ�����û��'\0'һ˵��ǰ��Ч���ݸ���
}Str;

//�����ַ�����ʼ����
void StrAssign(Str *s,const char *chars)
{
	assert(s != NULL && chars != NULL);
	int len = strlen(chars);
	if(len > SIZE)
	{
		return;
	}
	for(int i = 0;i < len;i++)
	{
		s->elem[i] = chars[i];
	}
	s->length = len;
}
//���� t ������ s
void StrCpy(Str *s,Str *t)
{
	if(s->length < t->length)
	{
		return;
	}
	for(int i = 0;i < t->length;i++)
	{
		s->elem[i] = t->elem[i];
	}
	s->length = t->length;
}
//�жϴ��Ƿ�Ϊ��
bool IsEmpty(Str *s)
{
	return s->length == 0;
}
//�󴮵ĳ���
int GetLength(Str *s)
{
	return s->length;
}
//�����
void Clear(Str *s)
{
	s->length = 0;
}
//�� s ����ĵ� pos λ����ȡ����Ϊ len ���Ӵ���
// �ŵ� sub ����
bool SubStr(Str *sub,Str *s,int pos,int len)
{
	if(pos < 0 || len < 0 || pos + len > s->length)
	{
		return false;
	}
	for(int i = 0;i < len;i++)
	{
		sub->elem[i] = s->elem[pos+i];
	}
	sub->length = len;
	return true;
}
//�� pos λ�ò��� t
bool Insert(Str *s,int pos,Str *t)
{
	int lent = t->length;
	int lens = s->length;
	if(pos < 0 || lent+lens > SIZE)
	{
		return false;
	}
	//Ų����
	for(int i = lens-1;i >= pos ;i--)
	{
		s->elem[i+lent] = s->elem[i];
	}
	for(int i = 0;i < lent;i++)
	{
		s->elem[pos+i] = t->elem[i];
	}
	s->length = s->length+t->length;
	return true;
}

//�� s ��������Ӵ� sub,�� pos λ�ÿ�ʼ�ĵ�һ�����ϵģ�
//�����±�
int BF(Str *s,Str *sub,int pos);

//�� pos λ�ÿ�ʼɾ�� len ������
bool DeletePos(Str *s,int pos,int len);

//�� pos λ�ÿ�ʼɾ���Ӵ� t;
bool Delete(Str *s, int pos, Str *t)
{
	int
}

//�� v �滻�� pos λ�ÿ�ʼ�ĵ�һ�� t;
bool Replace(Str *s,Str *t,Str *v,int pos);

//�����е� t �滻�� v
bool ReplaceAll(Str *s,Str *t,Str *v);

void Show(Str *s)
{
	for (int i = 0;i < s->length;i++)
	{
		printf("%c", s->elem[i]);
	}
	printf("\n");
}
void Destroy(Str *s)
{
}
int BF(Str *s,Str *sub, int pos)//ʱ�临�Ӷ�O��n*M����������*�ִ�����
{
int i = pos;
int j = 0;
int lensub = sub->length;
int lens = s->length;
while (lensub > 0 && lens > 0)
{
	if (sub->elem[i] == s->elem[j])
	{
		i++;j++;
	}
	else 
	{
		j = 0;i = i - j + 1;
	}
	if (j >= s->length)return true;
}
return- 1;
}
bool Replace(Str *s, Str *t, Str *v, int pos)//�����еĵ� T �滻�� v
{

}