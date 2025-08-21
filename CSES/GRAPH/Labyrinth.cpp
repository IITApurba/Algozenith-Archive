#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define INF 1e9

using state = pair<int, int>;
#define F first
#define S second

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int n, m;
vector<string> arr;

vector<vector<int>> vis;
vector<vector<int>> dist;
vector<vector<state>> parent;

void print_dis()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << dist[i][j] << "\t";
        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << parent[i][j].F << "," << parent[i][j].S << "\t";
        cout << endl;
    }
}

bool is_inside(int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < m)
        return 1;
    else
        return 0;
}

vector<state> neighbours(state cur)
{
    vector<state> ans;
    for (int k = 0; k < 4; k++)
    {
        int nx = cur.F + dx[k];
        int ny = cur.S + dy[k];

        if (is_inside(nx, ny) && arr[nx][ny] != '#')
            ans.push_back({nx, ny});
    }

    return ans;
}

void bfs(state st)
{
    vis = vector<vector<int>>(n, vector<int>(m, 0));
    dist = vector<vector<int>>(n, vector<int>(m, INF));
    parent = vector<vector<state>>(n, vector<state>(m, {-1, -1}));

    queue<state> q;

    dist[st.F][st.S] = 0;
    q.push(st);

    while (!q.empty())
    {
        //***...DO BFS ALGO...***//
        state cur = q.front();
        q.pop();

        if (vis[cur.F][cur.S])
            continue;

        vis[cur.F][cur.S] = 1;

        for (auto v : neighbours(cur))
        {
            if (!vis[v.F][v.S])
            {
                dist[v.F][v.S] = dist[cur.F][cur.S] + 1;
                parent[v.F][v.S] = cur;
                q.push(v);
            }
        }
    }
}

void solve()
{
    // Implicit Graph -> Good Graph Problem
    cin >> n >> m;
    arr.resize(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    state st, en;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (arr[i][j] == 'A')
                st = {i, j};
            else if (arr[i][j] == 'B')
                en = {i, j};

    bfs(st);

    // print_dis();

    // cout << endl;

    if (vis[en.F][en.S])
    {
        cout << "YES\n";
        cout << dist[en.F][en.S] << endl;

        vector<state> path;
        state cur = en;
        while (cur != make_pair(-1, -1))
        {
            path.push_back(cur);
            cur = parent[cur.F][cur.S];
        }

        reverse(path.begin(), path.end());

        string ansstr = "";

        for (int i = 1; i < path.size(); i++)
        {
            int chx = path[i].F - path[i - 1].F;
            int chy = path[i].S - path[i - 1].S;

            if (chx == 1)
                ansstr += "D";
            else if (chx == -1)
                ansstr += "U";
            else if (chy == 1)
                ansstr += "R";
            else if (chy == -1)
                ansstr += "L";
            else
            {
                // cout << "Something Wrong!!!!" << endl;
                assert(1 == 0);
            }
        }

        cout << ansstr << endl;
    }
    else
        cout << "NO\n";
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