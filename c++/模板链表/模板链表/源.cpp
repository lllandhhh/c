#include<iostream>
using namespace std;
template<class T>
class Link
{
public:
	Link() {}
	~Link(){}
	void insertHead(const T &val);
	bool query(const T &val);
private:
	struct Node {
		Node(T data = T()) :mdata(data), mpnext(NULL)
		{

		}
		T mdata;
		Node *mpnext;
	};
};

template<class T>
void Link<T>::insertHead(const T & val)
{
	Node *getNode = new Node ();
	getNode->mpnext = Node->mpnext;
	getNode->mdata = val;
}
