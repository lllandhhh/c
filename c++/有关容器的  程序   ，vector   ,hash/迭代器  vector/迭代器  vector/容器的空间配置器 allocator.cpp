#include <iostream>
using namespace std;

// 实现容器的空间配置器
template<typename T>
class Allocator
{
public:
	T* allocate(size_t size) // 开辟内存
	{
		return (T*)malloc(size);
	}
	void deallocate(void *ptr) // 释放内存
	{
		free(ptr);
	}
	void construct(T *ptr, const T &val) // 构造
	{
		new (ptr) T(val);
	}
	void destroy(T *ptr) // 析构
	{
		ptr->~T();
	}
};

template<typename T,
	typename allocator = Allocator<T>>
	class Vector
{
public:
	// 按指定size进行构造，size个空间，没有元素
	Vector(int size = 0)
		:mCur(0), mSize(size)
	{
		if (size == 0)
		{
			mpVec = nullptr;
		}
		else
		{
			//mpVec = new T[mSize];
			mpVec = mAllocator.allocate(mSize * sizeof(T));
		}
	}
	// 按指定size进行构造,添加size个元素，元素值是val
	Vector(int size, const T &val)
		:mCur(size), mSize(size)
	{
		mpVec = new T[mSize];
		for (int i = 0; i < mSize; ++i)
		{
			mpVec[i] = val;
		}
	}
	// 按[first, last)区间的元素来构造Vector
	Vector(T *first, T *last)
	{
		int size = last - first;
		mSize = size;
		mpVec = new T[mSize];
		for (mCur = 0; first < last; ++first)
		{
			mpVec[mCur++] = *first;
		}
	}
	~Vector()
	{
		//delete[]mpVec; 
		// 析构有效的对象
		for (int i = 0; i < mCur; ++i)
		{
			mAllocator.destroy(mpVec + i);
		}
		// 释放内存
		mAllocator.deallocate(mpVec);
	}
	// 从末尾添加元素
	void push_back(const T &val)
	{
		if (full())
			resize();
		//mpVec[mCur++] = val;
		mAllocator.construct(mpVec + mCur, val);
		mCur++;
	}
	// 从末尾删除元素
	void pop_back()
	{
		if (empty())
			return;
		--mCur;
		mAllocator.destroy(mpVec + mCur);
	}
	bool full()const { return mCur == mSize; }
	bool empty()const { return mCur == 0; }
	// 返回容器元素的个数
	int size()const { return mCur; }
	// Vector的迭代器
	class iterator
	{
	public:
		iterator(T *p = nullptr) :_ptr(p),first(p), last(p+size()){}

		
		bool operator!=(const iterator &it)
		{
			return _ptr != it._ptr;
		}
		void operator++() { _ptr++; }
		T& operator*() { return *_ptr; }

		// 给it迭代器的位置，插入一个值为val的对象,返回插入位置的新的迭代器
		iterator insert(iterator it, const T &val);
	
		// 删除it迭代器指向的位置，返回删除位置的最新的迭代器
		iterator erase(iterator it)
		{
			T *p = it._ptr;
			while (last._ptr >p)
			{
				mAllocator.destroy(p);
				mAllocator.construct(p, *(p + 1));
				p++:
			}
			last._ptr--;
		}

	private:
		iterator first; // 指向起始位置
		iterator last; // 最后一个元素的下一个位置
		iterator _end; // 指向末尾的下一个位置
		allocator mAllocator;  // 存储容器的空间配置器
		T *_ptr;
	};
	iterator begin() { return iterator(mpVec); }
	iterator end() { return iterator(mpVec + size()); }

private:
	T *mpVec;
	int mCur;
	int mSize;
	allocator mAllocator;  // 存储容器的空间配置器



						   // 容器内存2倍扩容
	void resize()
	{
		if (0 == mSize)
		{
			mpVec = mAllocator.allocate(sizeof(T));
			mSize = 1;
			mCur = 0;
		}
		else
		{
			T *newdata = mAllocator.allocate(sizeof(T)*mSize * 2);
			for (int i = 0; i < mSize; i++)
			{
				mAllocator.construct(newdata + i, mpVec[i]);
			}
			for (int i = 0; i < mSize; i++)
			{
				mAllocator.destroy(mpVec + i);
			}
			mAllocator.deallocate(mpVec);
			mpVec = newdata;
			mSize *= 2;
		}
	}
};

class A
{
public:
	A() :p(new int[2]) { cout << "A()" << endl; }
	A(const A &src) { cout << "A(const A&)" << endl; }
	~A() { cout << "~A()" << endl; }
private:
	int *p;
};
int main()
{

	//A a1, a2, a3;
	//cout << "------------" << endl;

	//// 这里只需要空间，不需要构造对象  malloc
	//Vector<A> vec(100);
	//vec.push_back(a1);
	//vec.push_back(a2);
	//vec.pop_back();
	//vec.push_back(a3);
}