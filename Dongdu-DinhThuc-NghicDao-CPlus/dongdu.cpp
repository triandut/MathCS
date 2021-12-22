// CACH 1
#include <iostream>
#include <math.h>
using namespace std;

// int main()
// {
// 	double a, m, n;
// 	cout << "nhap a: ";
// 	cin >> a;
// 	cout << "nhap m: ";
// 	cin >> m;
// 	cout << "nhap n: ";
// 	cin >> n;
// 	cout << "ket qua: " << fmod(pow(fmod(a, n), m), n);
// 	// su dung cong thuc : (a ^ m) mod n = ((a mod n) ^ m) mod n
// 	// 					fmod(x, y)
// 	// trả về phần dư của phép chia x / y
// }

// CACH 2: De quy
#include <iostream>
using namespace std;

int dongdu(int a, int m, int n)
{
	if (m == 0)
	{
		return 1;
	}
	if (m % 2 == 0)
	{
		return dongdu(a, m / 2, n) * dongdu(a, m / 2, n);
	}
	else
	{
		return a * dongdu(a, m - 1, n) % n;
	}
}
int main()
{
	int a, m, n;
	cout << "Nhap a = ";
	cin >> a;
	cout << "Nhap m = ";
	cin >> m;
	cout << "Nhap n = ";
	cin >> n;
	cout << dongdu(a, m, n);
	return 0;
}