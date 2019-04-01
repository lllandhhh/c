#include<iostream>
using namespace std;
#define SIZE 20
class CSeqstact
{
public:
	void init(int size);//初始化
	void push(int val );//入栈
	void pop();//出栈
	void top();//获取栈顶元素
	bool full();//判满
	bool empty();//判空
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