#include"Str.h"
#include<assert.h>
#include<stdio.h>
#include<string.h>
typedef struct Str
{
	char elem[SIZE];
	int length;//在串里面没有'\0'一说当前有效数据个数
}Str;

//利用字符串初始化串
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
//将串 t 拷贝到 s
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
//判断串是否为空
bool IsEmpty(Str *s)
{
	return s->length == 0;
}
//求串的长度
int GetLength(Str *s)
{
	return s->length;
}
//串清空
void Clear(Str *s)
{
	s->length = 0;
}
//从 s 里面的第 pos 位置提取长度为 len 的子串，
// 放到 sub 里面
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
//在 pos 位置插入 t
bool Insert(Str *s,int pos,Str *t)
{
	int lent = t->length;
	int lens = s->length;
	if(pos < 0 || lent+lens > SIZE)
	{
		return false;
	}
	//挪数据
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

//在 s 里面查找子串 sub,从 pos 位置开始的第一个符合的，
//返回下标
int BF(Str *s,Str *sub,int pos);

//从 pos 位置开始删除 len 个长度
bool DeletePos(Str *s,int pos,int len);

//从 pos 位置开始删除子串 t;
bool Delete(Str *s, int pos, Str *t)
{
	int
}

//用 v 替换从 pos 位置开始的第一个 t;
bool Replace(Str *s,Str *t,Str *v,int pos);

//将所有的 t 替换成 v
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
int BF(Str *s,Str *sub, int pos)//时间复杂段O（n*M）主串长度*字串长度
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
bool Replace(Str *s, Str *t, Str *v, int pos)//将所有的的 T 替换成 v
{

}