#pragma once
#define INIT_SIZE 10
typedef struct DSqlist
{
	int *elem;//�洢���ݵ��ڴ�
	int usedsize;//��Ч���ݸ���
	int size;//�ܵ�Ԫ��
}DSqlist,*PDSqlist;
void InitList(PDSqlist psq);

bool Insert(PDSqlist psq,int pos,int val);

int Search(PDSqlist Psq,int pos,int key);//���� key ֵ

bool DeletePos(PDSqlist Psq,int pos,int *rtv);//ɾ�� pos λ�õ�ֵ

bool Delete(PDSqlist Psq,int pos,int key);//ɾ��һ�� key ֵ

void Clear(PDSqlist psq);

void Destroy(PDSqlist psq);

void Show(PDSqlist psq);