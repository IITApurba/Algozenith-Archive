#include <bits/stdc++.h>
// #include "debug.cpp"
using namespace std;

typedef long long ll;

const int mod = 1e9;

// ncr table using pascale triangle

int ncr[10001][10001];
void precompute()
{
    for (int i = 0; i <= 10; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
            {
                ncr[i][j] = 1;
            }
            else
            {
                ncr[i][j] = (ncr[i - 1][j - 1] + ncr[i - 1][j]) % mod;
            }
        }
    }
}

void solve()
{
    int n;
    cin >> n;

    for (int r = 0; r <= n; r++)
    {
        cout << ncr[n][r] << " ";
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    precompute();

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}