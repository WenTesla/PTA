#include<iostream>
#include<string>
#include<algorithm>
#define ll long long
using namespace std;
ll up, down, a, b;
//判断最小公约数
ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}


int main() {
	down = 1;
	int n;
	char c;//取代'/'
	cin >> n;
	while (n--)
	{
		cin >> a >> c >> b;
		//分子分母通分
		up = a * down + b * up;//分子
		down = down * b;//分母
		ll x = abs(gcd(up,down));//求最小公约数
		//约分
		up /= x;
		down /= x;
	}
	if (up % down == 0)//整数
	{
		cout << up / down << endl;
	}
	else
	{
		if (up/down)
		{
			cout << up / down << " ";
		}
		cout << up - up / down * down << '/' << down << endl;
	}
	return 0;

}
