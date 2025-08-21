#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
vector<int> g[100100];
int dep[100100];
int par[100100];

void dfs(int node, int parent, int depth)
{
    dep[node] = depth;
    par[node] = parent;

    for (auto v : g[node])
    {
        if (v != parent)
        {
            dfs(v, node, depth + 1);
        }
    }
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1, 0, 0);

    int maxch = 1;

    for (int i = 2; i <= n; i++)
    {
        if (dep[i] > dep[maxch])
            maxch = i;
    }

    dfs(maxch, 0, 0);

    maxch = 1;

    for (int i = 2; i <= n; i++)
    {
        if (dep[i] > dep[maxch])
            maxch = i;
    }

    cout << dep[maxch] << endl;
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