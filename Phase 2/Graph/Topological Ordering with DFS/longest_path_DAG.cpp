#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;

vector<vector<int>> g;
vector<int> vis;

vector<int> topo;

void dfs(int node)
{
    vis[node] = 1;
    for (int v : g[node])
        if (!vis[v])
            dfs(v);

    topo.push_back(node);
}

int dp[100100];
int rec(int node)
{ // Longest path starting at node
    if (dp[node] != -1)
        return dp[node];
    int ans = 1;
    for (int v : g[node])
        ans = max(ans, 1 + rec(v));

    return dp[node] = ans;
}
void solve()
{
    cin >> n >> m;

    g.resize(n + 1);
    vis.resize(n + 1, 0);
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    // Longest path in DAG

    // int ans = 0;
    // for (int i = 1; i <= n; i++)
    // {
    //     ans = max(ans, rec(i));
    // }

    // cout << ans << endl;

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs(i);
    }

    int final = 0;
    for (auto node : topo)
    {
        int ans = 1;
        for (int v : g[node])
            ans = max(ans, 1 + dp[v]);
        
        dp[node] = ans;
        final = max(final,dp[node]);
    }

    cout << final << endl;
    

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