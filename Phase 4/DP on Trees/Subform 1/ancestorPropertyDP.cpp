#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

int n, m;
vector<int> g[100005];

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int dp[100005][20];

int dfs(int node, int gc, int pp)
{
    if (g[node].size() == 0 || (g[node].size() == 1 && pp != 0))
    {
        return gc == 1;
    }

    if (dp[node][gc] != -1)
        return dp[node][gc];

    int ans = 0;

    for (int col = 1; col <= m; col++)
    {
        int temp = 1;
        int cntch = 0;
        for (auto v : g[node])
        {
            if (v != pp)
            {
                cntch++;
                temp *= dfs(v, gcd(gc, col), pp);
            }
        }

        if (cntch == 0)
        {
            if (gcd(gc, col) == 1)
                ans++;
        }
        else
        {
            ans += temp;
        }
    }

    return dp[node][gc] = ans;
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int ans = dfs(1, 0, 0);

    cout << ans << endl;
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