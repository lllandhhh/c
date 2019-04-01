//#include <iostream>
//
//using namespace std;
//
//typedef unsigned int UINT;
//typedef unsigned char UCHAR;
//
//int main()
//{
//	UINT i = 0x12345678;
//	cout << hex << i << endl;
//	UCHAR *p = (UCHAR*)&i;
//	UINT num, num1, num2, num3, num4;
//	num1 = (*p) << 24;
//	num2 = (*(p + 1))<<16;
//	num3 = (*(p + 2))<<8;
//	num4 = (*(p + 3));
//	num = num1 + num2 + num3 + num4;
//
//	cout << "num1:" <<  num1 << endl;    
//	cout << "num2:" <<  num2 << endl;
//	cout << "num3:" <<  num3 << endl;
//	cout << "num4:" <<  num4 << endl;
//	cout << "num:" <<  num << endl;
//	int m;cin >> m;
//	return 0;
//
//}

//#include <iostream>
//using namespace std;
//void Diaohuan(char *p, char i[])
//{
//	int n = 6;
//	int m = 7;
//	for (m = 0;m<7;m++)
//	{
//		*(p + n) = i[m];
//		n--;
//	}
//	for (m = 0;m<7;m++)
//		cout << p[m];
//}
//int main()
//{
//	int m=7;
//	char i[7] ="abcdef";
//	char *a= "6666";
//	char *p =(char*)&a;
//	Diaohuan(p, i);
//	cin >> m;
//	return 0;
//
//}

//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int i = 2;
//	int m;
//	char *a[3] = {"Here", " is ", "Tulu"};
//	for (i;i >=0;i--)
//	{
//		cout << a[i];
//	}
//;
//	cin >> m;
//	return 0;
//}
