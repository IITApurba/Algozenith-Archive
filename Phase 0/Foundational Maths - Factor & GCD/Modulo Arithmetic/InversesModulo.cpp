#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

long long binPow(int a, int b, int m = MOD)
{
    a = a % m;

    if (b == 0)
        return 1;
    if (b == 1)
        return a % m;

    long long temp = binPow(a, b / 2, m);

    temp = (temp * temp) % m;

    if (b % 2 == 0)
        return temp;
    else
        return (a * temp) % m;
}

int main()
{
    
    // Claculate (5/70) % MOD

    long long num = 5;
    long long inv = binPow(70,MOD-1,MOD);

    long long ans = (num * inv) % MOD;

    cout << ans << endl;

    return 0;
}