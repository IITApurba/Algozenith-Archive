#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, m;
char a[1010][1010];
int vis[1010][1010];
int rooms = 0;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool is_valid(int i, int j)
{
    if (i >= 0 && i < n && j >= 0 && j < m && a[i][j] == '.' && vis[i][j] == 0)
        return 1;
    else
        return 0;
}

void dfs(int i, int j)
{
    vis[i][j] = 1;

    for (int a = 0; a < 4; a++)
    {
        int nx = i + dx[a];
        int ny = j + dy[a];

        if (is_valid(nx, ny))
            dfs(nx, ny);
    }
}

void solve()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == '#')
                vis[i][j] = 1;
        }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j])
            {
                dfs(i, j);
                rooms++;
            }
        }

    cout << rooms << endl;
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