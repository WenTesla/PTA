#include<iostream>
#include<math.h>
using namespace std;
/*一个正整数 N 的因子中可能存在若干连续的数字。例如 630 可以分解为 3×5×6×7，其中 5、6、7 就是 3 个连续的数字。给定任一正整数 N，要求编写程序求出最长连续因子的个数，并输出最小的连续因子序列。

输入格式：
输入在一行中给出一个正整数 N（1 < N < 2
	31
	）。

	输出格式：
	首先在第 1 行输出最长连续因子的个数；然后在第 2 行中按 因子1 * 因子2 * …… * 因子k 的格式输出最小的连续因子序列，其中因子按递增顺序输出，1 不算在内。

	输入样例：
	630
	输出样例：
	3
	5 * 6 * 7*/
bool isPrime(int x);
int main() {
	int x;
	cin >> x;
	//cout << sqrt(10) << endl;
	if (isPrime(x))//如果为素数，直接输出
	{
		cout << "1" << endl;
		cout << x << endl;
	}
	else//进行
	{
		int mul = 1;//表示乘积
		int maxcount = 0;
		int min = 0;
		int j;
		//使用滑动窗口
		for (int i = 2; i <= sqrt(x)+1; i++)
		{
			if (x % i == 0)//表示是一个因子，则进入
			{
				mul = i;
				double y = sqrt(x);
				for ( j = i + 1; j <= sqrt(x)+1; j++)
				{
					mul *= j;
					if (x%mul!=0)//mul不为因子,直接退出，因为本题要求连续因子
					{
						break;
					}
				}
				if (maxcount< (j-i))
				{
					maxcount = j - i;
					min = i;
				}
			}
		}
		cout << maxcount << endl;
		for (int i = 0; i < maxcount-1; i++)
		{
			cout << min + i <<"*";
		}
		cout << min + maxcount-1;
		//cout << endl;
	}
	system("pause");
}
bool isPrime(int x) {

	for (int i = 2; i <= sqrt(x); i++)//节约时间，开根号
	{
		if (x % i == 0)//取余
		{
			return false;//
		}
	}
	return true;//

}

