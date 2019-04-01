#include <iostream>
#include <vector>  // ʹ��vector����
#include <algorithm>  // ʹ�÷����㷨
#include <functional> // C++ STL�ĺ������� greater less greater_equal less_
#include <typeinfo>
#include <string>
#include<queue>
#include <list>
using namespace std;
#define max_hash_szie 0.75
template <typename T>
class list_hash
{
public:
	int operator()(const T  &val)
	{
		return val;
	}
};
template <>
class list_hash<string>
{
public:
	int operator()(const string &val)
	{
		int sum = 0;
		for (int i = 0; i < val.length(); ++i)
		{
			sum += (val[i] >> i);
		}
		return sum;
	}
};
template <typename T,typename HashType=list_hash<T>>
class list_hash_table
{
public:
	list_hash_table(int size = 3, double lf = 0.75)
		:_loadFactor(lf), hash_size(0)
	{
		// ����ϣ��������ռ��
		hash_vec.resize(size);

		// �������ϣֵ�Ķ�������Ͱ�Ĵ�С
	}
	void put(const  T &val)
	{
		_loadFactor = hash_size% hash_vec.size();
		if (_loadFactor > max_hash_szie)
		{
			hash_resize();
		}
		int index = _hash(val) % hash_vec.size();
		list <int> &cur_list = hash_vec[index];
		if (cur_list.empty())
		{
			cur_list.push_front(val);
			hash_size++;
		}
		else
			cur_list.push_front(val);
	}
	void hash_resize()
	{
		vector<list<int>> old_hash;
		old_hash.swap(hash_vec);
		hash_vec.resize(getPrime(old_hash.size()));
		for (auto it = old_hash.begin(); // it -> list<int>
			it != old_hash.end();
			++it)
		{
			if (!it->empty())
			{
				for (auto it1 = it->begin(); it1 != it->end();)
				{
					int index = _hash(*it1) % hash_vec.size();
					list<int> &mylist = hash_vec[index];
					if (!mylist.empty())
					{
						// 4.���Ͱ����һ��ռ�ã�_usedBuckets++
						hash_size++;
					}
					// �Ѿɵ�hash���е�list�ڵ�ֱ�Ӱᵽ�µĹ�ϣ����
					mylist.splice(mylist.begin(), *it, it1);
					it1 = it->begin();
				}
			}

		}
	}
	int getPrime(int n)
	{
		for (int i = n + 1;; ++i)
		{
			int k = sqrt(i);
			int j = 2;
			for (; j <= k; ++j)
			{
				if (i % j == 0)
					break;
			}
			if (j > k)
			{
				return i;
			}
			else
			{
				continue;
			}
		}
	}
	void show()
	{
		int i = 0;
		list<int> &mylist = hash_vec[i];
		for (int i = 0;i < hash_vec.size();i++)
		{
			list<int> &mylist = hash_vec[i];
		auto it = mylist.begin();
			for (it;it != mylist.end();it++)
			{
				cout << *it << endl;
			}
		}

	}
private:
	enum STATE { STATE_UNUSE, STATE_USE, STATE_USED };// û��  ������  ��ʹ��
	struct Node
	{
		Node(T data = T()):_data(data),_state(STATE_UNUSE)
		{
			next = NULL;
		}
			T  _data;
		STATE  _state;
	};
	vector <list<int >> hash_vec;
	double _loadFactor; // ��¼��������
	HashType _hash;  // ר�ż���T���Ͷ���Ĺ�ϣֵ��
	int hash_size;//����Ԫ�ظ�����
};
int main()
{
	list_hash_table<int> hash;

	for (int i = 0; i < 1000; i++)
	{
		hash.put(i);
	}
	hash.show();
		getchar();

	return 0;
}