#include <iostream>
using namespace std;

// ʵ�������Ŀռ�������
template<typename T>
class Allocator
{
public:
	T* allocate(size_t size) // �����ڴ�
	{
		return (T*)malloc(size);
	}
	void deallocate(void *ptr) // �ͷ��ڴ�
	{
		free(ptr);
	}
	void construct(T *ptr, const T &val) // ����
	{
		new (ptr) T(val);
	}
	void destroy(T *ptr) // ����
	{
		ptr->~T();
	}
};

template<typename T,
	typename allocator = Allocator<T>>
	class Vector
{
public:
	// ��ָ��size���й��죬size���ռ䣬û��Ԫ��
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
	// ��ָ��size���й���,���size��Ԫ�أ�Ԫ��ֵ��val
	Vector(int size, const T &val)
		:mCur(size), mSize(size)
	{
		mpVec = new T[mSize];
		for (int i = 0; i < mSize; ++i)
		{
			mpVec[i] = val;
		}
	}
	// ��[first, last)�����Ԫ��������Vector
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
		// ������Ч�Ķ���
		for (int i = 0; i < mCur; ++i)
		{
			mAllocator.destroy(mpVec + i);
		}
		// �ͷ��ڴ�
		mAllocator.deallocate(mpVec);
	}
	// ��ĩβ���Ԫ��
	void push_back(const T &val)
	{
		if (full())
			resize();
		//mpVec[mCur++] = val;
		mAllocator.construct(mpVec + mCur, val);
		mCur++;
	}
	// ��ĩβɾ��Ԫ��
	void pop_back()
	{
		if (empty())
			return;
		--mCur;
		mAllocator.destroy(mpVec + mCur);
	}
	bool full()const { return mCur == mSize; }
	bool empty()const { return mCur == 0; }
	// ��������Ԫ�صĸ���
	int size()const { return mCur; }
	// Vector�ĵ�����
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

		// ��it��������λ�ã�����һ��ֵΪval�Ķ���,���ز���λ�õ��µĵ�����
		iterator insert(iterator it, const T &val);
	
		// ɾ��it������ָ���λ�ã�����ɾ��λ�õ����µĵ�����
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
		iterator first; // ָ����ʼλ��
		iterator last; // ���һ��Ԫ�ص���һ��λ��
		iterator _end; // ָ��ĩβ����һ��λ��
		allocator mAllocator;  // �洢�����Ŀռ�������
		T *_ptr;
	};
	iterator begin() { return iterator(mpVec); }
	iterator end() { return iterator(mpVec + size()); }

private:
	T *mpVec;
	int mCur;
	int mSize;
	allocator mAllocator;  // �洢�����Ŀռ�������



						   // �����ڴ�2������
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

	//// ����ֻ��Ҫ�ռ䣬����Ҫ�������  malloc
	//Vector<A> vec(100);
	//vec.push_back(a1);
	//vec.push_back(a2);
	//vec.pop_back();
	//vec.push_back(a3);
}