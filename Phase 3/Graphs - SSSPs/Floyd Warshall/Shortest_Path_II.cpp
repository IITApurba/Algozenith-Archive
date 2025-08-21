#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

const int INF = 1e18;
int dist[505][505];

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;

    // Initialize distance matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }

    // Read and update edges (undirected graph)
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;  // convert to 0-based
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);  // bidirectional
    }

    // Floyd-Warshall Algorithm
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // Process queries
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;  // convert to 0-based
        if (dist[a][b] == INF)
            cout << -1 << '\n';
        else
            cout << dist[a][b] << '\n';
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
