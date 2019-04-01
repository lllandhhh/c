#include<iostream>
using namespace std;
// �����  ��OOPʵ��������ڴ��������ѭ������
class CircleQueue
{
public:
	CircleQueue(int size = 10)
	{
		mpQue = new int [size];
		mFront = 0;//ǰ
		mRear = 0;//β
		mSize = 10;//��С
	}
	~CircleQueue()
	{
		delete []mpQue;
	}
//	CircleQueue (const 	CircleQueue &)
	void addQue(int data);
	void delQue();
	int front();
	int back();
	bool full();//��
	bool empty();//��
private:
	int *mpQue;
	int mFront;
	int mRear;
	int mSize;
};
void CircleQueue::addQue(int data)
{
	if (full())
	{int count=0;
		int *mTmp = new int[mSize*2];
		for (int i = mFront ;i < mRear;i=(i + 1) % mSize)
		{
			mTmp[count++] = mpQue[i];
		}
	mFront=0;
	mRear=mSize-1;
		mSize = mSize * 2;
		delete[]mpQue;
		mpQue=mTmp;	
	}
		mpQue[mRear] = data;
		mRear = (mRear + 1) % mSize;
}
void CircleQueue::delQue()
{
	if (empty());
	else
	{
		mFront=(mFront+1)%mSize;
	}
}
bool  CircleQueue::full()//��
{
	if (mFront == (mRear + 1) % mSize)return true;
	else  return false;
}
bool CircleQueue::empty()//��
{
	return((mRear - mFront) ==0);
}
int CircleQueue::front()
{
	if (empty())return 0;
	else
	{
	 cout<< mpQue[mFront];
	 mFront = (mFront + 1) % mSize;
	}
	return 0;
}
int  CircleQueue::back()
{
	if (empty())return 0;
	else
	{
		cout << mpQue[mRear];
		mRear = (mRear -1) % mSize;
	}
	return 0;
}
int main()
{
	CircleQueue a;
	for(int i=0;i<40;i++)
	{
		a.addQue(i);
	}
	a.delQue();
	a.delQue();
	a.delQue();
	a.delQue();
	while (!a.empty())
	{
		a.front();
}
	getchar();
	return 0;
}