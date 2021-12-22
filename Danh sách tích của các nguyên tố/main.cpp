#include<iostream>
using namespace std;

int main()
{
    int n;
    int temp;
    cin >> n;
    for (int i = 2;i*i <= n;i++){
        temp = 0;
        while (n % i == 0){
            temp++;
            n /= i;
        }
        if (temp != 0) cout << i << "^" << temp << " ";
        if (n == 0) break;
    }
    return 0;
}