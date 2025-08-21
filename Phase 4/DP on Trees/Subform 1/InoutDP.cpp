#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

int n, m;
vector<int> g[100005];

int indp[100005];
int outdp[100005];

void dfsin(int node, int par)
{
    // Initialize the inDP
    indp[node] = 0;

    for (auto ch : g[node])
    {
        if (ch != par)
        {
            dfsin(ch, node);
            indp[node] = max(indp[ch] + 1, indp[node]);
        }
    }
}

void dfsout(int node, int par, int outValue)
{
    outdp[node] = outValue;

    int max1 = -1, max2 = -1;
    for (auto ch : g[node])

        if (ch != par)

            if (indp[ch] > max1)
            {
                max2 = max1;
                max1 = indp[ch];
            }
            else if (indp[ch] > max2)
                max2 = indp[ch];

    for (auto ch : g[node])
    {
        int siblingMax = -1;

        if (ch != par)
            if (indp[ch] == max1)
                siblingMax = max2;
            else
                siblingMax = max1;

        int newOut = max(outValue + 1, siblingMax + 2);
        dfsout(ch, node, newOut);
    }
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfsin(1, 0);
    dfsout(1, 0, 0);

    for (int i = 1; i <= n; ++i)
    {
        cout << "Node " << i << ": indp = " << indp[i] << ", outdp = " << outdp[i] << '\n';
    }

    for (int i = 1; i <= n; ++i)
        cout << "Node " << i << ": " << max(indp[i], outdp[i]) << '\n';
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