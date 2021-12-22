#include <iostream>
using namespace std;
bool Check(long long n)
{
    long long sum = 0;
    for (long long i = 1; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            sum += i;
        }
    }
    if (sum == n)
        return true;
    return false;
}
int main()
{
    long long n;
    cout << "Nhap vao n =";
    cin >> n;
    for (long long i = 1; i <= n; i++)
    {
        if (Check(i))
            cout << i << endl;
    }
}
