#include <unordered_map>
#include<iostream>
using namespace std;
class refcunt
{
public:
	void add(void *ptr)
	{
		mrefcontmap[ptr]++;
	}
	void del(void *ptr)
	{
		auto it = mrefcontmap.find(ptr);
		if (it != mrefcontmap.end())
		{
			it->second--;
			if (it->second == 0)
				mrefcontmap.erase(ptr);
		}
	}
	int get(void *ptr)
	{
		auto it = mrefcontmap.find(ptr);
		if (it != mrefcontmap.end())
		{
			return it->second;
		}
		return -1;
	}
private:
	unordered_map<void *, int>mrefcontmap;

};

template <typename T>
class CS
{
public:
	CS(T*ptr = nullptr)
		:mptr(ptr)
	{
		if (mptr != nullptr)mrefcut.add(mptr);
	}
	~CS() {
		mrefcut.del(mptr);
		if (0 == mrefcut.get(mptr))
			delete mptr;
	}
		T *operator ->()
		{
			return mptr;
		}
		T &operator *()
		{
			return *mptr;
		}
		CS(const CS<T>&str):mptr(str.mptr)
		{
			if (mptr != nullptr)mrefcut.add(mptr);
		}
		const T&operator*()const { return *mptr; }
		CS<T>& operator=(const CS &src)
		{
			if (this == &src)
				return *this;

			mrefcut.del(mptr);
			if (0 == mrefcut.get(mptr))
				delete mptr;

			mptr = src.mptr;
			if (mptr != nullptr)
			{
				mrefcut.add(mptr);
			}

			return *this;
		}
private:
	T *mptr;
	refcunt mrefcut;
};

int main()
{
	CS<int> ptr1(new int);
	CS<int> ptr2 = ptr1;

	*ptr2 = 20;
	*ptr1 = 30;

	CS<int> ptr3(new int);
	ptr2 = ptr3;
	return 0;
}