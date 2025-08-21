#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

int n, m;
vector<vector<pair<int, int>>> g; // {to, cost}
vector<int> dis;

void bfs(int sc)
{
    deque<int> dq;
    dis[sc] = 0;
    dq.push_back(sc);

    while (!dq.empty())
    {
        int x = dq.front();
        dq.pop_front();

        for (auto &[v, cost] : g[x])
        {
            if (dis[v] > dis[x] + cost)
            {
                dis[v] = dis[x] + cost;
                if (cost == 0)
                    dq.push_front(v);
                else
                    dq.push_back(v);
            }
        }
    }
}

void solve()
{
    cin >> n >> m;

    g.resize(n + 1);
    dis.assign(n + 1, 1e9);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back({b, 0});
        g[b].push_back({a, 1});
    }

    bfs(1);

    cout << (dis[n] == 1e9 ? -1 : dis[n]) << endl;

    g.clear();
    dis.clear();
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;

    while (t--)
        solve();

    return 0;
}
