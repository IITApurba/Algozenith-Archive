#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<vector<int>> g;
vector<int> cats;
int n, m;
int ans = 0;

void dfs(int u, int p = -1, int cnt = 0)
{
    if (cats[u])
        cnt++;
    else
        cnt = 0;

    if (cnt > m)
        return;

    if (g[u].size() == 1 && u != 1)
    {
        ans++;
        return;
    }

    for (int v : g[u])
    {
        if (v == p)
            continue;
        dfs(v, u, cnt);
    }
}

void solve()
{
    cin >> n >> m;

    g.resize(n + 1);
    cats.resize(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> cats[i];

    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(1);

    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;

    while (t--)
        solve();

    return 0;
}