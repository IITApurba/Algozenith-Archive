#include <bits/stdc++.h>
using namespace std;

vector<int> g[200200];
int parent[200200];
int depth[200200];

void dfs(int node, int dep, int par)
{
    depth[node] = dep;
    parent[node] = par;
    for (auto &neigh : g[node])
    {
        if (neigh != par)
        {
            dfs(neigh, dep + 1, node);
        }
    }
}

int dfs_to_count(int node, int dep, int par, int len)
{
    int result = (dep == len) ? 1 : 0;
    for (auto &neigh : g[node])
    {
        if (neigh != par)
        {
            result += dfs_to_count(neigh, dep + 1, node, len);
        }
    }
    return result;
}

int findCenter(int node, int diameter)
{
    int steps = diameter / 2;
    while (steps--)
    {
        node = parent[node];
    }
    return node;
}

void solve()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    if (n <= 2)
    {
        cout << 1;
        return;
    }
    // First DFS to find one end of diameter
    dfs(1, 0, 0);
    int maxNode = 1;
    for (int i = 2; i <= n; ++i)
    {
        if (depth[maxNode] < depth[i])
        {
            maxNode = i;
        }
    }

    // Second DFS to find the other end and diameter
    dfs(maxNode, 0, 0);
    int otherEnd = maxNode;
    for (int i = 1; i <= n; ++i)
    {
        if (depth[otherEnd] < depth[i])
        {
            otherEnd = i;
        }
    }

    int diameter = depth[otherEnd];

    if (diameter & 1)
    {
        // Odd diameter: center is an edge
        int c1 = findCenter(otherEnd, diameter);
        int c2 = parent[c1];

        long long count1 = dfs_to_count(c1, 0, c2, diameter / 2);
        long long count2 = dfs_to_count(c2, 0, c1, diameter / 2);

        cout << count1 * count2 << endl;
    }
    else
    {
        // Even diameter: center is a node
        int c = findCenter(otherEnd, diameter);

        vector<long long> subtree_counts;
        for (auto &child : g[c])
        {
            subtree_counts.push_back(dfs_to_count(child, 1, c, diameter / 2));
        }

        long long ans = 0;
        long long prefix_sum = 0;

        for (auto count : subtree_counts)
        {
            ans += prefix_sum * count;
            prefix_sum += count;
        }

        cout << ans << endl;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}