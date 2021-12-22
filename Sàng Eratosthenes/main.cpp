#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cout << "Nhap n = ";
    cin >> n;
    bool *arr = new bool[n + 1];
    for (ll i = 2; i * i <= n; i++)
    {
        for (ll j = i * 2; j <= n; j = j + i)
        {
            if (arr[j] == false)
                arr[j] = true;
        }
    }
    for (ll i = 2; i <= n; i++)
    {
        if (arr[i] == false)
        {
            cout << i << " ";
        }
    }
}