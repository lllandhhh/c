#include<iostream>
using namespace std;
#define SIZE 20
class CSeqstact
{
public:
	void init(int size);//��ʼ��
	void push(int val );//��ջ
	void pop();//��ջ
	void top();//��ȡջ��Ԫ��
	bool full();//����
	bool empty();//�п�
	void spdelete();
private:
	int * mStact;
	int mtop;
	int mSize;
};
 void CSeqstact::init(int size)
 {
	 mStact = new int[size];
	 mtop = 0;
	 mSize = size;
}
 void CSeqstact::push( int val)
 {
	 if (full())
 {
		 int *pmStact = new int[mSize * 2];
		 for (int i = 0;i < mSize;i++)
		 {
			 pmStact[i] = mStact[i];
			 }
		 delete[]mStact;
		 mStact = pmStact;
 }
	 mStact[mtop++] = val;
 }
 void CSeqstact::pop()
 {
	 mtop--;
 }

 void CSeqstact::top()
 {
	 cout << mStact[mtop - 1];
 }

 bool CSeqstact::full()
 {
	 return mtop == mSize ;
 }

 bool CSeqstact::empty()
 {
	 return mtop==0;
 }
 void CSeqstact :: spdelete()
 {
	 delete  mStact;
 }
 int main()
 {
	 CSeqstact a;
	 a.init(5);
	 for (int i = 0;i < 20;i++)
	 {
		 a.push(i);
	 }
	 while (!a.empty())
	 {
		 a.top();
		 a.pop();
	 }
	a. spdelete();
	 getchar();

	 return 0;
 }