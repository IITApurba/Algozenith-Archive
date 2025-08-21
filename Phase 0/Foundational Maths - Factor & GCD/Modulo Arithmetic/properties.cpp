#include <bits/stdc++.h>
using namespace std;

int add(int a, int b, int mod)
{
    return (a%mod + b%mod) % mod;
}

int sub(int a, int b, int mod)
{
    return (a%mod - b%mod + mod) % mod;
}

int mul(int a, int b, int mod)
{
    return (a%mod * b%mod) % mod;
}

int main()
{
    int a = 8;
    int b = 5;
    int mod = 7;

    cout << add(a, b, mod) << endl;
    cout << sub(a, b, mod) << endl;
    cout << mul(a, b, mod) << endl;
    
    return 0;
}