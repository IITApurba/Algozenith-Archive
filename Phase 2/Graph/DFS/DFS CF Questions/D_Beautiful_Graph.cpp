#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 998244353;

int n, m;
vector<vector<int>> g;
vector<int> vis;
vector<int> color;

ll power(ll base, ll exp, ll mod)
{
    ll result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

bool dfs(int node, int c, int &cnt1, int &cnt2)
{
    vis[node] = 1;
    color[node] = c;
    (c == 1) ? cnt1++ : cnt2++;

    for (auto child : g[node])
    {
        if (!vis[child])
        {
            if (!dfs(child, 3 - c, cnt1, cnt2))
                return false;
        }
        else if (color[child] == color[node])
        {
            return false;
        }
    }
    return true;
}

void solve()
{
    cin >> n >> m;
    g.assign(n + 1, vector<int>());
    vis.assign(n + 1, 0);
    color.assign(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    ll ways = 1;

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            int cnt1 = 0, cnt2 = 0;
            if (!dfs(i, 1, cnt1, cnt2))
            {
                cout << 0 << endl;
                return;
            }
            ways = (ways * (power(2, cnt1, MOD) + power(2, cnt2, MOD)) % MOD) % MOD;
        }
    }

    cout << ways << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
