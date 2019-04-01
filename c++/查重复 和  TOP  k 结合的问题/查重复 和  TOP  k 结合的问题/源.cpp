int main()
{
	vector<int> vec;
	for (int i = 0; i < 200000; ++i)
	{
		vec.push_back(rand());
	}

	// �����������У��ҳ��ظ���������ǰ10�����ֲ����д�ӡ
	// �������� + ���ȼ�����   xxx : �ظ�23��

	// 1.ͳ���������ֵ��ظ�����   

	// ����һ����ʽ��ϣ�� key:���ֵ�ֵ  value:�����ظ��Ĵ���
	unordered_map<int, int> numMap;
	// ����vec�����������������з������е����֣��ײ��ͨ��������������
	// ����C++11�����﷨����foreach
	for (int val : vec)
	{
#if 0
		// ��map��val
		auto it = numMap.find(val);
		if (it == numMap.end())
		{
			// û�ҵ������[val, 1]
			numMap.insert(make_pair(val, 1));
		}
		else
		{
			// �ҵ��ˣ���ֵ��1  first second
			it->second++;
		}
#endif
		// ��val������map�в��ң����val�����ڣ�numMap[val]�����һ��[val, 0]
		// ��ôһ������ֵ��Ȼ��++���õ�һ��[val, 1]��ôһ��������
		// ���val���ڣ�numMap[val]�պ÷��ص���val���ֶ�Ӧ��second�ظ��Ĵ�����ֱ��++
		numMap[val]++;
	}

	// ��Ϊ���Ҫ��¼���ֺ��ظ��Ĵ�����������Ҫ���һ��������
	struct Node
	{
		Node(int v, int c) :val(v), count(c) {}
		// ΪʲôҪʵ��operator>����ΪС��������Ҫ�Ƚ�Node����Ĵ�С
		// greater >   less <
		bool operator>(const Node &src)const
		{
			return count > src.count;
		}
		int val; // ��ʾ���ֵ�ֵ
		int count; // ��ʾ�����ظ��Ĵ���
	};

	// 2.��topk ��
	// �ȶ���һ��С����
	priority_queue<Node, vector<Node>, greater<Node>> minheap;

	// �����ѷ�k������
	int k = 0;
	auto it = numMap.begin();

	// �ȴ�map���ж�10�����ݵ�С�����У�����top 10��С���ѣ���С��Ԫ���ڶѶ�
	for (; it != numMap.end() && k < 10; ++it, ++k)
	{
		minheap.push(Node(it->first, it->second));
	}

	// ��K+1��ĩβ��Ԫ�ؽ��б������ͶѶ�Ԫ�رȽ�
	for (; it != numMap.end(); ++it)
	{
		// ���map���е�ǰԪ���ظ��������ڣ��Ѷ�Ԫ�ص��ظ����������滻
		if (it->second > minheap.top().count)
		{
			minheap.pop();
			minheap.push(Node(it->first, it->second));
		}
	}
	// ����ʣ�µľ����ظ���������ǰk��
	while (!minheap.empty())
	{
		Node node = minheap.top();
		cout << node.val << " : " << node.count << endl;
		minheap.pop();
	}

	return 0;
}
