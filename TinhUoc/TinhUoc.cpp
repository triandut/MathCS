#include<iostream>
#include "lib/bigint.h"
using namespace std;

void UocSo(int n)
{
    cout << "Uoc so cua " << n << ": "; 
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        cout << i << " ";
    }
}

long long TongUocSo(int n)
{
    long long tong = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            tong += i;
        }
    }
    return tong;
}

bigint TichUocSo(int n)
{
    bigint tich = 1;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            tich *= i;
        }
    }
    return tich;
}
int main()
{
    int N = 20000;
    UocSo(N);
    cout << "\n" << "Tong Uoc Cac So: " << TongUocSo(N);
    cout << "\n" << "Tich Uoc Cac So: " << TichUocSo(N);
}