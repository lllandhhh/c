#pragma once
#define SIZE 10
typedef struct Str
{
	char elem[SIZE];
	int length;//�ڴ�����û��'\0'һ˵��ǰ��Ч���ݸ���
}Str;
//�����ַ�����ʼ����
void StrAssign(Str *s,const char *chars);
//���� t ������ s
void StrCpy(Str *s,Str *t);
//�жϴ��Ƿ�Ϊ��
bool IsEmpty(Str *s);
//�󴮵ĳ���
int GetLength(Str *s);
//�����
void Clear(Str *s);
//�� s ����ĵ� pos λ����ȡ����Ϊ len ���Ӵ��� �ŵ� sub ����
bool SubStr(Str *sub,Str *s,int pos,int len);
//�� pos λ�ò��� t
bool Insert(Str *s,int pos,Str *t);

//�� s ��������Ӵ� sub,�� pos λ�ÿ�ʼ�ĵ�һ�����ϵģ������±�
int BF(Str *s,Str *sub,int pos);
//�� pos λ�ÿ�ʼɾ�� len ������
bool DeletePos(Str *s,int pos,int len);
//�� pos λ�ÿ�ʼɾ���Ӵ� t;
bool Delete(Str *s,int pos,Str *t);

//�� v �滻�� pos λ�ÿ�ʼ�ĵ�һ�� t;
bool Replace(Str *s,Str *t,Str *v,int pos);
//�����е� t �滻�� v
bool ReplaceAll(Str *s,Str *t,Str *v);

void Show(Str *s);

void Destroy(Str *s);
int BF(Str *s, Str *sub, int pos);
bool Replace(Str *s, Str *t, Str *v, int pos);