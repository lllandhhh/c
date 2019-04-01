#include <iostream>
#include <vector>  // ʹ��vector����
#include <algorithm>  // ʹ�÷����㷨
#include <functional> // C++ STL�ĺ������� greater less greater_equal less_
#include <typeinfo>
#include <string>
#include<queue>
#define HASHTABLE  0.75
using namespace std;

// �����ϣֵ����
template<typename T>
class CHash
{
public:
	int operator()(const T &val)
	{
		  // Ĭ���ó���������
		return val;
	}
}; // string  User  People

template<>
class CHash<string>
{
public:
	int operator()(const string &val)
	{
		// hello  olleh
		int sum = 0;
		for (int i = 0; i < val.length(); ++i)
		{
			sum += (val[i] >> i);
		}
		return sum;
	}
};

// ����̽�ⷨʵ�ֵĹ�ϣ��ṹ 
template<typename T, typename HashType = CHash<T>>
class CHashTable
{
public:
	CHashTable(int size = 3, double lf = 0.75)
		:_loadFactor(lf),hash_size(0)
	{
		// ����ϣ��������ռ��
		_hashVec.resize(size);
	
		// �������ϣֵ�Ķ�������Ͱ�Ĵ�С
	}
	void put(const T &val)                                           //��ֵ
	{

		int  index = _hash(val) % _hashVec.size();//�����ϣֵ
		for (int i = index;; i = (i + 1) % _hashVec.size())
		{
			
			if (_hashVec[i]._state != STATE_USE)
			{
				hash_size++;
				_hashVec[i]._data = val;
				_hashVec[i]._state = STATE_USE;
				hash_add();
				break;
			}
			// STATE_UNUSE STATE_USE STATE_USEDδʹ��   ʹ��    ��ʹ��
		
		}
	}
	int get_prime_number()
	{
	
		int a[] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97 };
		for (int i = 0;;i++)
		{
			if (_hashVec.size() <a[i])
				return a[i];
		}
	}
	void hash_add()
	{
		_loadFactor = hash_size/ _hashVec.size();
		if (_loadFactor >= HASHTABLE)
		{
		                                           //����
			vector<Node> old_hash;
			old_hash.resize(get_prime_number());
			for (int i = 0;i < _hashVec.size();i++)
			{
				if (_hashVec[i]._state == STATE_USE)
				{
					int index = _hashVec[i]._data%old_hash.size();//�����ϣֵ
					for (int k = index;; k = (k + 1) % _hashVec.size())
					{
						if (old_hash[k]._state == STATE_UNUSE)
						{
							old_hash[k]._data = _hashVec[i]._data;
							old_hash[k]._state = STATE_USE;
							break;
						}
					}
				}
			}
			_hashVec.erase(_hashVec.begin(), _hashVec.end());
			_hashVec = old_hash;
		}
	}
	void show()
	{
		for (int i = 0;i < _hashVec.size();i++)
		{
			cout << _hashVec[i]._data<<endl;
		}
	}
	void find_hash_number(const T &val)
	{
		int index = val%_hashVec.size();	int k = index;
		for (int i = index;i < _hashVec.size();i++)
		{
			if (_hashVec[i]._data == val)
			{
				cout << "�±�Ϊ" << i;
				k++;
			
			}
			if (_hashVec[i]._state == STATE_UNUSE)
			{
				break;
			}
		}
		if (k == index)cout << "û�������";
	}
	void delete_hash_number(const T &val)
	{
		int index = val%_hashVec.size();
		for (int i = index;i < _hashVec.size();i++)
		{
			if (_hashVec[i]._data == val)
			{
				cout << "�±�Ϊ" << i;
				_hashVec[i]._data = 0;
				_hashVec[i]._state = STATE_USED;
			}
			if (_hashVec[i]._state == STATE_UNUSE)
			{
				break;
			}
		}
	
	}
	
	
private:
	// STATE_UNUSE   ɾ�� STATE_USED 0
	enum STATE { STATE_UNUSE, STATE_USE, STATE_USED };
	struct Node
	{
		Node(T data = T())
			:_data(data), _state(STATE_UNUSE)
		{}
		T _data;
		STATE _state;
	};
	vector<Node> _hashVec;
	double _loadFactor; // ��¼��������
	HashType _hash;  // ר�ż���T���Ͷ���Ĺ�ϣֵ��
	int hash_size;//����Ԫ�ظ�����
};

typedef unsigned int unit;
int main()
{
	CHashTable<int> hash;
	for (int i = 0;i < 14;i++)
	{
		hash.put(i);
	}
	hash.put(88);
	hash.put(88);
	hash.show();
	//hash.find_hash_number(89);
	hash.delete_hash_number(88);
	hash.show();
	hash.put(99);
	hash.put(77);
	hash.show();
	hash.find_hash_number(77);
	getchar();
#if 0
	vector<unit>vec;
	priority_queue<int> maxHeap;
	for (unit i = 0;i < 2000000;++i)
	{
		vec.push_back(rand() + i);
	}
	for (int i = 0;i < 10;++i)
	{
		maxHeap.push(vec[i]);
	}
	while (!vec.empty() )
	{
		if (vec.back()< maxHeap.top())
		{
			maxHeap.pop();
			maxHeap.push(vec.back());
		}
		vec.pop_back();
	}
	for (int i = 0;i < 10;++i)
	{
		cout << maxHeap.top()<<endl;
		maxHeap.pop();
	}
	getchar();
#endif
	return 0;
}

