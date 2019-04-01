#include<iostream>
using namespace std;
struct Node
{
	//对于对象的初始化，都通过构造函数进行
	Node(int data = 0)
	{
		mdata = data;
		mpnext = NULL;
	}
	int mdata;
	Node *mpnext;
};
class CLink
{
public:
	CLink();
	~CLink();
	CLink(const CLink &link);
//	CLink& operator=(const CLink &link);

	void insertHead(int data);
	void insertTail(int data);

void removeNode(int data); // 删除值为data的所有节点
	void show();
private:
	Node *mpHead;
};

CLink::CLink()
{
	mpHead =new Node();
}

CLink::~CLink()
{
	Node *p = mpHead;
	while (p != NULL)
	{
		mpHead=mpHead ->mpnext;
		delete p;
		p = mpHead;
	}
}

CLink::CLink(const CLink & link)
{
	mpHead = new Node();
	Node *plist = mpHead;
	Node *p = link.mpHead->mpnext;
	while (p)
	{
		Node *pnew = new Node(p->mdata);
		plist->mpnext = pnew;
		p = p->mpnext;
	}
}

void CLink::insertHead(int data)
{
	Node *p = new Node(data);
	p->mdata = data;
	p->mpnext = mpHead->mpnext;
	mpHead->mpnext = p;
}

void CLink::insertTail(int data)
{
	Node *p = new Node(data);
	Node *cur = mpHead;
	p->mdata = data;
	while (cur->mpnext != NULL)
	{
		cur = cur->mpnext;
	}
	cur->mpnext = p;
}

void CLink::removeNode(int data)
{
	Node *pcur = mpHead;
	Node *ppcur = mpHead->mpnext;

	while (ppcur!= NULL)
	{
		if (ppcur->mdata == data)
		{
			pcur->mpnext = ppcur->mpnext;
			delete ppcur;
			ppcur = pcur->mpnext;
		}
		pcur = pcur->mpnext;
		ppcur = ppcur->mpnext;
	}
}

void CLink::show()
{
	Node *cur = mpHead->mpnext;
	while (cur)
	{
		cout << cur->mdata;
		cur = cur->mpnext;
	}
}
int main()
{
	CLink a;
	a.insertHead(1);a.insertHead(2);a.insertHead(3);
	a.removeNode(2);
	a.show();
	getchar();
	return 0;

}