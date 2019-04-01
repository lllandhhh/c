#include<iostream>
using namespace std;
template<typename T>
class SeqStack // 模板名称 SeqStack<T> 必须指定实例化模板的类型
{
public:
	SeqStack(int size = 10)：mTop(0), mSize(size)
	{
		mpStack = new T[mSize];
	}
	~SeqStack()
	{
		delete[]mpStack;
	}
	SeqStack<T>(const SeqStack<T> &src)
	{
		mTop = src.mTop;
		mSize = src.mSize;
		for (int i = 0; i < mTop; i++)
		{
			mpStack[i] = src.mpStack[i];
		}
	}

	SeqStack<T>& operator=(const SeqStack<T> &src)
	{
		if (this == &src)
		{
			return *this;
		}

		delete[]mpStack;

		mTop = src.mTop;
		mSize = src.mSize;
		mpStack = new T[mSize];
		for (int i = 0; i < mTop; i++)
		{
			mpStack[i] = src.mpStack[i];
		}

		return *this;

	}
	void push(const T &val)
	{
		if (full())
		{
			T *cur = new T[mSize * 2];
			for (int i = 0;i < mSize;i++)
			{
				cur[i]= mpStack[i];
			}
			mSize = mSize * 2；
				delete[]mpStack;
			mpStack = cur;
		}
		mpStack[mTop++] = va;
	}
	void pop()
	{if(!empty())
		mTop--;
	else cout<<"空栈"；
	}
	T top()const
	{
		return mpStack[mTop-1];
	}
	bool full()const
	{
		if (mTop == mSize)
			return ture;
		else return false;
	}
	bool empty()const
	{
		if (mTop == 0)
			return ture;
		else return false;
	}
private:
	T *mpStack;
	int mTop;
	int mSize;
};