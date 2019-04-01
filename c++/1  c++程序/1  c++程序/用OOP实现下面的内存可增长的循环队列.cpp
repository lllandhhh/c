#include<iostream>
using namespace std;
// 任务二  用OOP实现下面的内存可增长的循环队列
class CircleQueue
{
public:
	CircleQueue(int size = 10)
	{
		mpQue = new int [size];
		mFront = 0;//前
		mRear = 0;//尾
		mSize = 10;//大小
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
	bool full();//满
	bool empty();//空
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
bool  CircleQueue::full()//满
{
	if (mFront == (mRear + 1) % mSize)return true;
	else  return false;
}
bool CircleQueue::empty()//空
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