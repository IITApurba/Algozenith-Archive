#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long
int n, m;
vector<vector<pair<int, int>>> g;

void solve()
{
    cin >> n >> m;
    g.assign(n + 1, {});

    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        g[u].push_back({v, wt});
    }

    vector<int> dist(n + 1, LLONG_MIN);
    dist[1] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        for (int u = 1; u <= n; u++)
        {
            if (dist[u] == LLONG_MIN)
                continue;
            for (auto [v, wt] : g[u])
            {
                if (dist[u] + wt > dist[v])
                {
                    dist[v] = dist[u] + wt;
                }
            }
        }
    }

    // Detect positive weight cycle reachable from node 1 and can reach node n
    vector<int> temp = dist;
    for (int u = 1; u <= n; u++)
    {
        if (dist[u] == LLONG_MIN)
            continue;
        for (auto [v, wt] : g[u])
        {
            if (dist[u] + wt > dist[v])
            {
                // Check if this cycle can reach node n
                // Use DFS/BFS from v to see if we can reach node n
                vector<bool> vis(n + 1, false);
                queue<int> q;
                q.push(v);
                vis[v] = true;

                while (!q.empty())
                {
                    int cur = q.front();
                    q.pop();
                    if (cur == n)
                    {
                        cout << "-1\n";
                        return;
                    }
                    for (auto [next, _] : g[cur])
                    {
                        if (!vis[next])
                        {
                            vis[next] = true;
                            q.push(next);
                        }
                    }
                }
            }
        }
    }

    cout << dist[n] << '\n';
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
