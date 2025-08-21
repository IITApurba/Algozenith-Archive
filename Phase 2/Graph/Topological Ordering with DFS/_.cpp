#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int n, m;
vector<vector<int>> g;
vector<int> in_degree;
vector<int> topo;
vector<ll> dp;

void topological_sort()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (in_degree[i] == 0)
            q.push(i);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for (int v : g[node])
        {
            if (--in_degree[v] == 0)
                q.push(v);
        }
    }
}

void solve()
{
    cin >> n >> m;
    g.resize(n + 1);
    in_degree.resize(n + 1, 0);
    dp.resize(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        in_degree[v]++;
    }

    topological_sort();

    dp[1] = 1; // Only one way to be at level 1 (starting point)

    for (int node : topo)
    {
        for (int v : g[node])
        {
            dp[v] = (dp[v] + dp[node]) % MOD;
        }
    }

    cout << dp[n] % MOD << endl; // Number of ways to reach level n
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    while (t--)
        solve();

    return 0;
}