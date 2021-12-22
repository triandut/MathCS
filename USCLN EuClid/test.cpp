#include <iostream>
#include<math.h>
using namespace std;
int sqr(int x) {
    return x*x;
}

int Pow(int a, int b, int MOD) {
    if (b == 0) return 1 % MOD;
    else
        if (b % 2 == 0)
            return sqr(pow(a, b/2)) % MOD;
        else
            return a * (sqr(pow(a, b/2)) % MOD) % MOD;
}
int main() {
  cout<<Pow(50,100,13);
}