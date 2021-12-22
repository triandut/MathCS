// #include <iostream>
// #include <math.h>
// using namespace std;

// int main()
// {
//     double a, m, n;
//     cout << "nhap a: ";
//     cin >> a;
//     cout << "nhap m: ";
//     cin >> m;
//     cout << "nhap n: ";
//     cin >> n;
//     cout << "ket qua: " << fmod(pow(fmod(a, n), m), n);
// }

#include <iostream>
using namespace std;

int power(long long a, int m, int n)
{
    int res = 1;

    if (a == 0)
        return 0;
    if (m == 0)
        return 1 % n;
    while (m > 0)
    {
        if (m & 1)
            res = (res * (a % n)) % n;
        m = m >> 1; // y = y/2
        a = (a * a) % n;
    }
    return res;
}

int main()
{
    int a, m, n;
    cout << "Nhap a: ";
    cin >> a;
    cout << "Nhap m: ";
    cin >> m;
    cout << "Nhap n: ";
    cin >> n;
    cout << "Ket qua:  " << power(a, m, n);
    return 0;
}

// This code is contributed by shubhamsingh10
