#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long
int n;

vector<int> g[100100];
int dep[100100];
int par[100100];
bool isLeaf[100100];
int subtreeSz[100100];
int numChild[100100];

void dfs(int node, int parent, int depth)
{
    dep[node] = depth;
    par[node] = parent;

    subtreeSz[node] = 1;

    numChild[node] = 0;

    for (auto v : g[node])
    {
        if (v != parent)
        {
            numChild[node]++;
            dfs(v, node, depth + 1);

            subtreeSz[node] += subtreeSz[v];
        }
    }

    if (numChild[node] == 0)
        isLeaf[node] = 1;
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

    // root is 1
    dfs(1, 0, 0);
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