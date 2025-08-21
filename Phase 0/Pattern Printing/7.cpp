#include <bits/stdc++.h>
using namespace std;

char cpp = 'A';

/*
A
B C
D E F
G H I J
K L M N O
*/

void fun(int i, int j, int n)
{
    if (i >= j)
    {
        cout << cpp << " ";
        cpp++;
    }
}

void solve()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fun(i, j, n);
        }
        cout << endl;
    }
}

int main()
{
    int testcase = 1;
    // cin >> testcase;

    while (testcase--)
        solve();

    return 0;
}