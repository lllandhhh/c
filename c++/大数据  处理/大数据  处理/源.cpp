#include<vector>
#include <iostream>
#include <unordered_map>
#include<queue>
#include <algorithm>
#include <functional>
using namespace std;





int main()
{
	FILE *pf = fopen("data.dat", "w");
	for (int i = 0;i < 800000;i++)
	{
		int data = rand();
		fwrite(&data, 4, 1, pf);
	}
	fclose(pf);

}