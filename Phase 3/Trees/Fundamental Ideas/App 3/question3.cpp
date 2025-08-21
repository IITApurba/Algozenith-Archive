#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

vector<vector<int>> adj;
vector<int> val, ans;

void dfs(int u, int parent, int current_min, int current_max)
{
    // Compute the answer for node u
    ans[u] = max(
            abs(val[u] - current_min),
            abs(val[u] - current_max));

    // Update the min/max along the path
    int next_min = min(current_min, val[u]);
    int next_max = max(current_max, val[u]);
    
    // Recurse on children
    for (int v : adj[u])
    {
        if (v == parent)
            continue;
        dfs(v, u, next_min, next_max);
    }
}

void solve()
{
    int n;
    cin >> n;
    int root;
    cin >> root;

    // Read node values (1-indexed)
    val.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> val[i];
    }

    // Build adjacency list
    adj.assign(n + 1, {});
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Prepare answer array
    ans.assign(n + 1, 0);

    // Start DFS from root, with min = max = val[root]
    dfs(root, 0, val[root], val[root]);

    // Answer:
    // ans[u] = max ( val[u]- Min[u] , val[u] - Max[u] )

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
