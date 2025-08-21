#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long
int n, m;
vector<vector<int>> g;
vector<int> dis;
vector<int> parent;

void bfs(int sc)
{
    queue<int> q;
    q.push(sc);

    dis[sc] = 0;
    parent[sc] = -1;

    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        for (auto v : g[x])
        {
            if (dis[v] > dis[x] + 1)
            {
                dis[v] = dis[x] + 1;
                parent[v] = x;
                q.push(v);
            }
        }
    }
}

void solve()
{
    cin >> n >> m;

    g.resize(n + 1);
    dis.assign(n + 1, 1e9);
    parent.assign(n + 1, -1);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    bfs(1);

    if (dis[n] == 1e9)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }

    vector<int> path;
    for (int cur = n; cur != -1; cur = parent[cur])
        path.push_back(cur);

    reverse(path.begin(), path.end());

    cout << path.size() << '\n';
    for (int x : path)
        cout << x << ' ';
    cout << '\n';

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
