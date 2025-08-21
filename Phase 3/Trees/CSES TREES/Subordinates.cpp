#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

const int N = 10;
vector<int> g[N];
int subordinates[N];

int dfs(int u)
{
    int cnt = 0;
    for (int v : g[u])
    {
        cnt += 1 + dfs(v); // Count v and all of v's subordinates
    }
    subordinates[u] = cnt;
    return cnt;
}

void solve()
{
    int n;
    cin >> n;

    for (int i = 2; i <= n; i++)
    {
        int boss;
        cin >> boss;
        g[boss].push_back(i);
    }

    debug(g);

    dfs(1);

    for (int i = 1; i <= n; i++)
    {
        cout << subordinates[i] << " ";
    }
    cout << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}
