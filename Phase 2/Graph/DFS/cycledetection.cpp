#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;

typedef long long ll;

int n, m;
vector<vector<int>> g;
vector<int> vis;

bool is_cycle_present = false;

void dfs(int node, int par)
{
    vis[node] = 1;

    for (auto v : g[node])
        if (!vis[v])
            dfs(v,node);
        else if(v!=par){
            //Cycle is present
            is_cycle_present = true;
        }
}

void solve()
{
    cin >> n >> m;

    g.resize(n + 1);
    vis.assign(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs(i,0);

    if(is_cycle_present)
        cout << "Yes parent present" << endl;
    else
        cout << "No parent present" << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    while (t--)
        solve();

    return 0;
}