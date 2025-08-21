#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long
int n, k;
vector<vector<int>> a;

void solve()
{
    cin >> n >> k;
    a.resize(n, vector<int>(10));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 10; j++)
            cin >> a[i][j];

    
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