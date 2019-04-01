int main()
{
	vector<int> vec;
	for (int i = 0; i < 200000; ++i)
	{
		vec.push_back(rand());
	}

	// 在这组数字中，找出重复次数最大的前10个数字并进行打印
	// 无序容器 + 优先级队列   xxx : 重复23次

	// 1.统计所有数字的重复次数   

	// 定义一个链式哈希表 key:数字的值  value:数字重复的次数
	unordered_map<int, int> numMap;
	// 遍历vec这个容器，这个容器中放了所有的数字，底层就通过迭代器遍历的
	// 这是C++11的新语法，叫foreach
	for (int val : vec)
	{
#if 0
		// 在map找val
		auto it = numMap.find(val);
		if (it == numMap.end())
		{
			// 没找到，添加[val, 1]
			numMap.insert(make_pair(val, 1));
		}
		else
		{
			// 找到了，给值加1  first second
			it->second++;
		}
#endif
		// 拿val数字在map中查找，如果val不存在，numMap[val]会插入一个[val, 0]
		// 这么一个返回值，然后++，得到一个[val, 1]这么一组新数据
		// 如果val存在，numMap[val]刚好返回的是val数字对应的second重复的次数，直接++
		numMap[val]++;
	}

	// 因为结果要记录数字和重复的次数，所以需要打包一个类类型
	struct Node
	{
		Node(int v, int c) :val(v), count(c) {}
		// 为什么要实现operator>，因为小根堆里面要比较Node对象的大小
		// greater >   less <
		bool operator>(const Node &src)const
		{
			return count > src.count;
		}
		int val; // 表示数字的值
		int count; // 表示数字重复的次数
	};

	// 2.求topk 大
	// 先定义一个小根堆
	priority_queue<Node, vector<Node>, greater<Node>> minheap;

	// 先往堆方k个数据
	int k = 0;
	auto it = numMap.begin();

	// 先从map表中读10个数据到小根堆中，建立top 10的小根堆，最小的元素在堆顶
	for (; it != numMap.end() && k < 10; ++it, ++k)
	{
		minheap.push(Node(it->first, it->second));
	}

	// 把K+1到末尾的元素进行遍历，和堆顶元素比较
	for (; it != numMap.end(); ++it)
	{
		// 如果map表中当前元素重复次数大于，堆顶元素的重复次数，则替换
		if (it->second > minheap.top().count)
		{
			minheap.pop();
			minheap.push(Node(it->first, it->second));
		}
	}
	// 堆中剩下的就是重复次数最大的前k个
	while (!minheap.empty())
	{
		Node node = minheap.top();
		cout << node.val << " : " << node.count << endl;
		minheap.pop();
	}

	return 0;
}
