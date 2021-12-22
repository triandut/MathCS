#include <iostream>
#include <math.h>
using namespace std;

void tichSoNguyenTo(long n)
{
	for (long i = 2; i <= n; i++)
	{
		int dem = 0;
		while (n % i == 0)
		{
			++dem;
			n /= i;
		}
		if (dem > 0)
		{
			if (dem > 1)
				cout << i << "^" << dem << " ";
			else
				cout << i << " ";
			if (n > 1)
			{
				cout << " * ";
			}
		}
	}
}