#include <iostream>
using namespace std;
int Euclid_GDC(int a, int b)
{
    if (b == 0)
        return a;
    return Euclid_GDC(b, a % b);
}
int main()
{
    int a, b;
    cout << "a = " ; cin >> a ;
    cout << "b = " ; cin >> b;
    cout << Euclid_GDC(a, b);
}