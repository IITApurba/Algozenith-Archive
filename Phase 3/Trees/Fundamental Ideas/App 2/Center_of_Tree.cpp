#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

int n;
vector<int> g[200100];
int dep[200100];
int par[200100];
int diameter = 0;

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
    for (int i = 1; i <= n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    // My first task is to find the diameter of the tree
    dfs(1, 0, 0);
    int far1 = 1;
    for (int i = 2; i <= n; i++)
    {
        if (dep[i] > dep[far1])
            far1 = i;
    }

    dfs(far1, 0, 0);
    int far2 = 1;
    for (int i = 2; i <= n; i++)
    {
        if (dep[i] > dep[far2])
            far2 = i;
    }

    diameter = dep[far2];

    int step = diameter / 2;

    int center1 = far2;
    while (step--)
        center1 = par[center1];

    if (diameter % 2 == 0)
    {
        cout << center1 << "\n";
    }
    else
    {
        cout << -1 << "\n";
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