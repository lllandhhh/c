//�����Ķ���   �ṹ��Ķ���
#pragma once //Ԥ��ͷ�ļ��ظ�����
#define SIZE 10
typedef struct Sqlist
{
	int elem[SIZE];
	int usedsize;
}Sqlist,*PSqlist;

void InitSqlist(PSqlist Psq);//��ʼ��

bool Insert(PSqlist Psq,int pos ,int val);//�� pos λ�ò��� val ֵ

int Search(PSqlist Psq,int pos,int key);//��posλ�ÿ�ʼ���� key ֵ

bool DeletePos(PSqlist Psq,int pos,int *rtv);//ɾ�� pos λ�õ�ֵ

bool Delete(PSqlist Psq,int pos,int key);//ɾ��һ�� key ֵ

bool GetElem(PSqlist Psq,int pos,int *rtv);

int GetLength(PSqlist Psq);

void Clear(PSqlist Psq);

void Destory(PSqlist Psq);

void Show(PSqlist Psq);