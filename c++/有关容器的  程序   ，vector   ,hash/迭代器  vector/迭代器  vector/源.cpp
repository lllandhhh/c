#include<iostream>
using namespace std;
template<typename T>
class Vector
{
public:
	// ��ָ��size���й��죬size���ռ䣬û��Ԫ��
	Vector(int size = 0):mSize(size), mCur(0)
	{
		mpVec = new T[size];
	}
	// ��ָ��size���й���,���size��Ԫ�أ�Ԫ��ֵ��val
	Vector(int size, const T &val = T())
	{
		mCur = size;
		mSize = size;
		mpVec = new T[size];
		for(int i=0;i<size;i++)
		{
			mpVec[i] = val;
		}
	}
	// ��[first, last)�����Ԫ��������Vector
	Vector(T *first, T *last)
	{
		int size = last - first;
		mpVec = new T[size];
	for(mCur = 0; first < last; ++first)
		{
		mpVec[mCur++] = *first;
		}
	}
	// ��ĩβ���Ԫ��
	void push_back(const T &val)
	{
		if (full())
			resize();
		mpVec[mCur++] = val;
	}
	// ��ĩβɾ��Ԫ��
	void pop_back()
	{
		if (empty())
		{
			mCur--;
		}
	}
	bool full()const
	{
		return(mCur == mSize);
	}
	bool empty()const
	{
		return (mCur == 0);
	}
	// ��������Ԫ�صĸ���
	int size()const
	{
		return mCur;
	}
	// Vector�ĵ�����
	class iterator
	{
	public :
		iterator(T *mpVec) :pur(mpVec)
		{
		}
		bool operator!=(const iterator &it)
		{
			return pur != it.pur;
		}
		void operator++() { pur++; }
		T& operator*() { return *pur; }
	private:
		T *pur;
	};
	iterator begin()
	{
		return mpVec;
	}
	iterator end()
	{
		return (mpVec + size());
	}

private:
	T *mpVec;
	int mCur;
	int mSize;
	// �����ڴ�2������
	void resize()
	{
		if (mSize == 0)
		{
			mpVec = new T[1];
			mCur = 0;
			mSize = 1;
		}
		if (mCur == mSize)
		{
			T * p = new T[mSize * 2];
			for (int i = 0;i < mSize;i++)
			{
				p[i] = mpVec[i];
			}
			mSize = mSize * 2;
			delete[] mpVec;
			mpVec = p;
		}
	}
};
int main()
{
	Vector<int> vec1; // �ײ㲻���ٿռ�
	vec1.push_back(10); // 0 - 1 - 2 - 4 - 8 - 16 - 32 - 64 - 128
	vec1.push_back(20);
	for (int i = 0; i < 20; ++i)
	{
		vec1.push_back(rand() % 100 + 1);
	}
	cout << vec1.size() << endl;

	// ��ͨ�õĵ�����������ʽ������vec1������ӡ���������е�Ԫ��ֵ
	Vector<int>::iterator it = vec1.begin();
	while(it != vec1.end())
	{
		cout << *it << " ";
		++it;
	}
	getchar();
	Vector<int> vec2(10, 20);
	int arr[] = { 12,4,56,7,89 };
	Vector<int> vec3(arr, arr + sizeof(arr) / sizeof(arr[0]));
	return 0;
}



