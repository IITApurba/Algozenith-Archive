#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100100;
int n;
vector<int> g[MAXN];
int dep[MAXN];
int par[MAXN];

int D;
int cnt = 0;

void dfs(int node, int parent, int depth)
{
    dep[node] = depth;
    par[node] = parent;
    if (depth == (D / 2 - 1))
        cnt++;
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
    for (int i = 1; i <= n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    // First DFS to find one end of the diameter
    dfs(1, 0, 0);
    int far1 = 1;
    for (int i = 2; i <= n; i++)
    {
        if (dep[i] > dep[far1])
            far1 = i;
    }

    // Second DFS from far1 to find the diameter and farthest node
    dfs(far1, 0, 0);
    int far2 = 1;
    for (int i = 2; i <= n; i++)
    {
        if (dep[i] > dep[far2])
            far2 = i;
    }
    // far1 and far2 are the two ends of the diameter
    // D is the diameter length
    D = dep[far2];

    cout << "Length of the diameter is " << D << "\n";

    // Find center(s)
    int step = D / 2;
    int center1 = far2;
    while (step--)
        center1 = par[center1];

    cout << "Center of the tree is at node: " << center1 << " ";

    int center2 = 0;
    if (D % 2 == 1)
    {
        center2 = par[center1];
        cout << center2 << "\n";
    }
    else
        cout << "\n";

    // Center1 and center2 are the centers of the tree

    // Clear and count nodes at depth D/2 - 1 from center(s)
    fill(dep, dep + n + 1, 0);
    cnt = 0;
    dfs(center1, 0, 0);

    if (D % 2 == 1)
    {
        fill(dep, dep + n + 1, 0);
        dfs(center2, 0, 0);
    }

    cout << "Number of nodes at depth D/2 - 1 from center(s): ";
    // Why is this useful?
    // It counts how many nodes are at depth D/2 - 1 from the center
    // This can be useful in various applications, such as balancing trees or finding optimal paths

    cout << cnt << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;

    while (t--)
        solve();

    return 0;
}
