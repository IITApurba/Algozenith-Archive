#include <bits/stdc++.h>
using namespace std;

int binpow(int a, int b, int mod)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;

    if (b % 2 == 0)
    {
        int x = binpow(a, b / 2, mod);
        return (x * x) % mod;
    }
    else
        return (a * binpow(a, b - 1, mod)) % mod;
}
int main()
{
    int a = 8;
    int b = 10000;

    int mod = 7;

    cout << binpow(a, b, mod) << endl;

    return 0;
}