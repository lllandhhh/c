//1����һ�����ֵĶ���������1�ĸ���   2  0000 0010    1
//2������һ�����֣�����������Ǽ�λ����
//˳���ӡÿһλ����       �����ӡÿһλ����
//12345       5       1 2 3 4 5        5 4 3 2 1
//3����쳲��������еĵ�40��ĺ�Ϊ���٣�
//1  1   2   3   5   8  13
//4����� 100 - 200 ֮��Ĳ��ܱ� 3 ��������
//5���� 100 - 200 ֮���ȫ��������
//6���κ�ϰ�� 3, 5, 8, 9, 10
//1.
//#include<iostream>
//using namespace std;
//void make(int n)
//{
//	int m = n;int k = 0;
//	do
//	{
//		if ((m % 2) == 1)k++;
//		m = m / 2;
//		
//		
//	} while (m!= 0);
//	cout <<"�м���һ"<< k << endl;
//}
//int main()
//{
//	int n;
//	cin >> n;int a;
//	 make(n);
//	cin >> a;
//	return 0;
//}

//2.
//#include<iostream>
//using namespace std;
//void make(int n)
//{
//	int m = n;int k = 0;
//	do
//	{
//		k++;
//		m = m / 10;
//	} while (m!=0);
//	cout <<"�м�λ��"<< k << endl;
//}
//int main()
//{
//	int n;int m = 0;
//	cin >> n;int a;
//	 make(n);
//	 cout << n << endl;
//	 while (n!= 0) {
//		 m = m * 10 + n % 10;
//		 n = n / 10;
//	 }
//	 cout << m << endl;
//	cin >> a;
//	return 0;
//}

//3.
//#include<iostream>
//using namespace std;
//int main()
//{
//	int i=0;
//	int p;
//	cout << "�������3+?��" << endl;
//	cin >> p;
//	int m = 1;int n = 1;int q=0;
//	for (i = 0;i <=p;i++)
//	{
//		q = m + n;
//		m = n;
//		n = q;
//
//	}
//	cout << n << endl;
//	cin >> i;
//	return 0;
//}
//4.
//#include<iostream>
//using namespace std;
//void math()
//{
//	for (int i = 100;i <= 200;i++)
//	{
//		if (i % 3)
//	 cout << i << endl;
//	}
//}
//int main()
//{
//	int i;
//	math ();
//	cin >> i;
//	return 0;
//}


////5.
//#include<iostream>
//using namespace std;
//void math()
//{
//	for (int i = 100;i <= 200;i++)
//	{
//		if (i % 2)
//	 cout << i << endl;
//	}
//}
//int main()
//{
//	int i;
//	math ();
//	cin >> i;
//	return 0;
//}