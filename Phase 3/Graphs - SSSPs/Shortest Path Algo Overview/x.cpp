#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long
#define F first
#define S second

int n, m, x, y, a, b;

bool check(int i, int j)
{
    if (i >= 1 && i <= n && j >= 1 && j <= m /*&&!blocked[i][j]*/)
        return 1;
    return 0;
}

int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};

int dis[1010][1010];

using state = pair<int, int>;

int bfs(int stx, int sty)
{
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            dis[i][j] = 1e9;
        }
    }

    queue<state> q;

    q.push({stx, sty});

    dis[stx][sty] = 0;

    while (!q.empty())
    {
        state cur = q.front();

        q.pop();

        for (int k = 0; k < 8; k++)
        {
            int nx = cur.F + dx[k];
            int ny = cur.S + dy[k];

            if (check(nx, ny) && dis[nx][ny] > dis[cur.F][cur.S] + 1)
            {
                dis[nx][ny] = dis[cur.F][cur.S] + 1;

                q.push({nx, ny});
            }
        }
    }
}

void solve()
{
    cin >> n >> m >> x >> y >> a >> b;

    bfs(x, y);

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            cout << dis[i][j] << " ";
        }
        cout << endl;
    }

    if (dis[a][b] == 1e9)
        cout << -1 << "\n"; // Destination unreachable
    else
        cout << dis[a][b] << "\n"; // Minimum knight moves
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