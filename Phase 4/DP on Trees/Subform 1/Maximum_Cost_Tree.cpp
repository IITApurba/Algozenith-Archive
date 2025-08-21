#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

const int MAXN = 100005;

vector<int> g[MAXN];

int A[MAXN], subtreeSum[MAXN], dp[MAXN];
int totalSum;

void dfs1(int u, int p, int depth)
{
    subtreeSum[u] = A[u];
    dp[1] += A[u] * depth;

    for (int v : g[u])
    {
        if (v != p)
        {
            dfs1(v, u, depth + 1);
            subtreeSum[u] += subtreeSum[v];
        }
    }
}

void dfs2(int u, int p)
{
    for (int v : g[u])
    {
        if (v != p)
        {
            dp[v] = dp[u] - subtreeSum[v] + (totalSum - subtreeSum[v]);
            dfs2(v, u);
        }
    }
}

void solve()
{
    int n;
    cin >> n;

    totalSum = 0;

    for (int i = 1; i <= n; ++i)
    {
        cin >> A[i];
        g[i].clear();
        totalSum += A[i];
        dp[i] = 0;
        subtreeSum[i] = 0;
    }

    for (int i = 1; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }


    dfs1(1, -1, 0);
    dfs2(1, -1);

    int mini = LLONG_MAX, maxi = LLONG_MIN;
    for (int i = 1; i <= n; ++i)
    {
        mini = min(mini, dp[i]);
        maxi = max(maxi, dp[i]);
    }

    cout << maxi << " " << mini << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
