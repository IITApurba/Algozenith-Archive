#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

int n, m;
int sx, sy, ex, ey;

#define F first
#define S second

int dx[] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[] = {2, -2, 1, -1, 2, -2, 1, -1};

using state = pair<int, int>;
vector<vector<int>> vis, dist;
vector<vector<state>> parent;
vector<vector<char>> arr;

bool is_inside(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

vector<state> neighbours(state cur)
{
    vector<state> ans;
    for (int k = 0; k < 8; k++)
    {
        int nx = cur.F + dx[k];
        int ny = cur.S + dy[k];

        if (is_inside(nx, ny) && arr[nx][ny] != '#')
            ans.push_back({nx, ny});
    }
    return ans;
}

int bfs(state sc)
{
    vis[sc.F][sc.S] = 1;
    dist[sc.F][sc.S] = 0;

    queue<state> q;
    q.push(sc);

    while (!q.empty())
    {
        state cur = q.front();
        q.pop();

        for (auto v : neighbours(cur))
        {
            if (!vis[v.F][v.S])
            {
                vis[v.F][v.S] = 1;
                dist[v.F][v.S] = dist[cur.F][cur.S] + 1;
                parent[v.F][v.S] = cur;
                q.push(v);
            }
        }
    }

    return dist[ex][ey];
}

void solve()
{
    cin >> n >> m;
    cin >> sx >> sy;
    cin >> ex >> ey;

    --sx, --sy, --ex, --ey;

    arr.assign(n, vector<char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    vis.assign(n, vector<int>(m, 0));
    dist.assign(n, vector<int>(m, -1));
    parent.assign(n, vector<state>(m, {-1, -1}));

    int ans = bfs({sx, sy});
    cout << ans << endl;
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
