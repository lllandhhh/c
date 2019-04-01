#include<iostream>
using  namespace std;
class Test
{
public:
	Test(int data) :mptr(new int(data)) {}
	~Test() { delete mptr; }
	int*& GetPtrRef() { return mptr; } 
		int*& GetPtrRef()const { return mptr; } 
private:
	int *mptr;
};
void main()
{
	Test t1(10);
	const Test t2(20);

	int *a1 = t1.GetPtrRef();
	int *&b1 = t1.GetPtrRef();
	const int *&c1 = t1.GetPtrRef();

	int *a2 = t2.GetPtrRef();
	int *&b2 = t2.GetPtrRef();
	const int *&c2 = t2.GetPtrRef();
}