#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

int n, m;
vector<pair<int, int>> g[100100];
int dis[100100];

void BFS01(int sc)
{
    deque<int> dq;

    for (int i = 1; i <= n; i++)
    {
        dis[i] = 1e9;
    }

    dis[sc] = 0;

    dq.push_back(sc);

    while (!dq.empty())
    {
        int xx = dq.front();
        dq.pop_front();

        for (auto &&v : g[xx])
        {
            int neigh = v.first;
            int cost = v.second;

            if (dis[neigh] > dis[xx] + cost)
            {
                dis[neigh] = dis[xx] + cost;

                if (cost == 0)
                    dq.push_front(neigh);
                else
                    dq.push_back(neigh);
            }
        }
    }
}

void solve()
{
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    int sc;
    cin >> sc;

    BFS01(sc);

    // t-> test case

    // for all the nodes we know the answer
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