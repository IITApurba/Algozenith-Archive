#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

const int MAXN = 1e5 + 5;
const int MAXK = 505;

vector<int> g[MAXN];
int cnt[MAXN][MAXK];
int res = 0;
int K;

void dfs(int u, int par)
{
    cnt[u][0] = 1;

    for (int v : g[u])
    {
        if (v == par)
            continue;

        dfs(v, u);

        // Count valid pairs between u and v's subtree
        for (int d1 = 0; d1 < K; ++d1)
        {
            int d2 = K - d1 - 1;
            if (d2 >= 0)
            {
                res += cnt[u][d1] * cnt[v][d2];
            }
        }

        // Merge cnt[v] into cnt[u]
        for (int d = 0; d < K; ++d)
        {
            cnt[u][d + 1] += cnt[v][d];
        }
    }
}

void clear(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        g[i].clear();
        for (int d = 0; d <= K; ++d)
            cnt[i][d] = 0;
    }
}

void solve()
{
    int n;
    cin >> n >> K;

    clear(n);

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    res = 0;
    dfs(1, 0);
    cout << res << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
