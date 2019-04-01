#include<vector>
#include<iostream>
using namespace std;
int main()
{
	vector<int>vec;
	cout << vec.size() << endl;
	cout << vec.empty() << endl;
	for (int i = 0;i < 20;i++)
	{
		vec.push_back(rand() % 100 + 1);
	}
	vector <int>::iterator it = vec.begin();

	while(it!=vec.end())
	{
		if (*it %2 == 0)
		{
			it=vec.erase(it);
		}
		else ++it;

	}
	for (int i = 0;i<vec.size();i++)
		cout << vec[i] << " ";
	cout << endl;

	vector <int>::iterator it1 = vec.begin();
while(it1!=vec.end())
	{
		it1=vec.insert(it1, *(it1)-1);
		it1=it1+2;
	}
	for (int i = 0;i<vec.size();i++)
		cout << vec[i] << " ";
	getchar();
	return 0;

}