#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;

typedef long long ll;
int n, m;
bool is_cycle = 0;

vector<vector<int>> g;
vector<int> col;
vector<int> parent;
vector<int> any_cycle;

vector<int> cntcycle;
vector<int> prefixorder;

void dfs(int node, int par)
{
    parent[node] = par;
    col[node] = 2;

    for (auto v : g[node])
    {
        // ADD FOR UNDIRECTED GRAPH ONLY :D
        // ✨✨✨✨✨
        if (v == parent[node])
            continue;

        if (col[v] == 1)
        { // Node - v is forming edge
            dfs(v, node);
        }
        else if (col[v] == 2)
        { // Node - v is back edge
            // We found a cycle !!
            if (is_cycle == 0)
            {
                int temp = node;
                while (temp != v)
                {
                    any_cycle.push_back(temp);
                    temp = parent[temp];
                }
                any_cycle.push_back(temp);
                reverse(any_cycle.begin(), any_cycle.end());
            }
            // Jis node mei hu usko ++ karo
            cntcycle[node]++;
            // Aur usko parent -- karo jasa hum prefix sum karte the
            cntcycle[parent[v]]--;
            is_cycle = 1;
        }
    }
    col[node] = 3;
    prefixorder.push_back(node);
}

void solve()
{
    cin >> n >> m;
    g.resize(n + 1);
    col.assign(n + 1, 1);
    parent.assign(n + 1, 0);
    cntcycle.assign(n + 1, 0);

    map<pair<int, int>, int> edgecnt;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x == y)
        {
            // Self loop
        }

        if (x > y)
            swap(x, y);
        edgecnt[{x, y}]++;

        if (edgecnt[{x, y}] > 1)
        {
            // Multiple Edge Cycle}
        }
        else
        {
            g[x].push_back(y);
            g[y].push_back(x);
        }
    }

    for (int i = 1; i <= n; i++)
        if (col[i] == 1)
            dfs(i, 0);

    debug(any_cycle);

    cout << endl;

    for (auto v : prefixorder)
        cntcycle[parent[v]] += cntcycle[v];

    int cntnode = 0;
    for (int i = 1; i <= n; i++)
        if (cntcycle[i] > 0)
            cntnode++;

    debug(cntnode);
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