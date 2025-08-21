#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

int n;
vector<vector<int>> g;
vector<int> sz, parent;

void dfs(int u, int p)
{
    parent[u] = p;
    sz[u] = 1;
    for (int v : g[u])
    {
        if (v == p)
            continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
}

void solve()
{
    cin >> n;
    g.assign(n + 1, {});
    sz.assign(n + 1, 0);
    parent.assign(n + 1, 0);

    // graph input
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // DFS to calculate subtree sizes
    dfs(1, 0);

    // sz[u] -> size of subtree rooted at u
    // parent[u] -> parent of u in the DFS tree

    // If node u is a centroid
    // Then: max( max sz[v] for v in children(u), n - sz[u] ) <= n / 2

    vector<int> centroids;
    for (int u = 1; u <= n; u++)
    {
        int maxChild = 0;

        for (int v : g[u])
        {
            if (v == parent[u])
                continue;
            maxChild = max(maxChild, sz[v]);
        }

        int rest = n - sz[u];

        int largestComp = max(maxChild, rest);

        if (largestComp <= n / 2)
        {
            centroids.push_back(u);
        }
    }

    // Output: either one or two centroids
    cout << centroids[0] << endl;
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
