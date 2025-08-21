#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

void solve()
{
    int N, K;
    cin >> N >> K;
    vector<vector<pair<int, int>>> adj(N + 1);
    int u, v;
    int w;
    for (int i = 0; i < N - 1; i++)
    {
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    vector<int> parent(N + 1, 0);
    vector<int> order;
    order.reserve(N);
    vector<int> stk;
    stk.reserve(N);
    vector<int> wt(N + 1, 0);

    // Build parent and order (preorder)
    stk.push_back(1);
    parent[1] = 0;
    while (!stk.empty())
    {
        int x = stk.back();
        stk.pop_back();
        order.push_back(x);
        for (auto &pr : adj[x])
        {
            int y = pr.first;
            if (y == parent[x])
                continue;
            parent[y] = x;
            wt[y] = pr.second;
            stk.push_back(y);
        }
    }

    vector<int> dp0(N + 1, 0), dp1(N + 1, 0);

    // Process in reverse order for post-order DP
    for (int i = N - 1; i >= 0; --i)
    {
        int node = order[i];
        int p = parent[node];
        long long base = 0;
        vector<long long> gains;
        gains.reserve(adj[node].size());

        for (auto &pr : adj[node])
        {
            int to = pr.first;
            if (to == p)
                continue;
            base += dp0[to];
            long long gain = dp1[to] + pr.second - dp0[to];
            if (gain > 0)
                gains.push_back(gain);
        }

        sort(gains.begin(), gains.end(), greater<long long>());
        long long add0 = 0;
        for (int j = 0; j < (int)gains.size() && j < K; ++j)
            add0 += gains[j];
        dp0[node] = base + add0;

        long long add1 = 0;
        if (K > 0)
        {
            for (int j = 0; j < (int)gains.size() && j < K - 1; ++j)
                add1 += gains[j];
        }
        dp1[node] = base + add1;
    }

    cout << dp0[1] << '\n';
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
