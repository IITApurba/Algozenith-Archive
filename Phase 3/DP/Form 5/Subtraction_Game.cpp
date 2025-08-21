#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

int dp[1000005];

int rec(int x)
{
    // base case
    if (x == 0)
        return 0;

    // cache check
    if (dp[x] != -1)
        return dp[x];

    // calculate
    int ans = 0;
    //(1<<i) = 2 ^ i
    for (int i = 0; (1 << i) <= x; i++)
    
        if (rec(x - (1 << i)) == 0)
        {
            ans = 1;
            break;
        }

    // save and return
    return dp[x] = ans;
}

void solve()
{
    memset(dp, -1, sizeof(dp));

    int tt;
    cin >> tt;
    while (tt--)
    {
        int x;
        cin >> x;
        if(rec(x))
            cout << "Vivek" << endl;
        else
            cout << "Abhishek" << endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;

    while (t--)
        solve();

    return 0;
}