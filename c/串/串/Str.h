#pragma once
#define SIZE 10
typedef struct Str
{
	char elem[SIZE];
	int length;//在串里面没有'\0'一说当前有效数据个数
}Str;
//利用字符串初始化串
void StrAssign(Str *s,const char *chars);
//将串 t 拷贝到 s
void StrCpy(Str *s,Str *t);
//判断串是否为空
bool IsEmpty(Str *s);
//求串的长度
int GetLength(Str *s);
//串清空
void Clear(Str *s);
//从 s 里面的第 pos 位置提取长度为 len 的子串， 放到 sub 里面
bool SubStr(Str *sub,Str *s,int pos,int len);
//在 pos 位置插入 t
bool Insert(Str *s,int pos,Str *t);

//在 s 里面查找子串 sub,从 pos 位置开始的第一个符合的，返回下标
int BF(Str *s,Str *sub,int pos);
//从 pos 位置开始删除 len 个长度
bool DeletePos(Str *s,int pos,int len);
//从 pos 位置开始删除子串 t;
bool Delete(Str *s,int pos,Str *t);

//用 v 替换从 pos 位置开始的第一个 t;
bool Replace(Str *s,Str *t,Str *v,int pos);
//将所有的 t 替换成 v
bool ReplaceAll(Str *s,Str *t,Str *v);

void Show(Str *s);

void Destroy(Str *s);
int BF(Str *s, Str *sub, int pos);
bool Replace(Str *s, Str *t, Str *v, int pos);