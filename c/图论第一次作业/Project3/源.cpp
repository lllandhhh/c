//1、求一个数字的二进制数中1的个数   2  0000 0010    1
//2、给定一个数字，求这个数字是几位数？
//顺序打印每一位数字       逆序打印每一位数字
//12345       5       1 2 3 4 5        5 4 3 2 1
//3、求斐波那契数列的第40项的和为多少？
//1  1   2   3   5   8  13
//4、输出 100 - 200 之间的不能被 3 整除的数
//5、求 100 - 200 之间的全部素数？
//6、课后习题 3, 5, 8, 9, 10
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
//	cout <<"有几个一"<< k << endl;
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
//	cout <<"有几位数"<< k << endl;
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
//	cout << "计算多少3+?项" << endl;
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