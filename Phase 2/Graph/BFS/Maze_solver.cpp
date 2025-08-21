#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;

typedef long long ll;
#define F first
#define S second
const int INF = 100;

/*
6 6
S . # . . .
. . . . . .
# . # . # .
. . . # . .
# # # # . #
F . . . . .
*/

int n, m;
vector<vector<char>> arr;

using state = pair<int, int>;

vector<vector<int>> vis;
vector<vector<int>> dis;
// map<state,int> dis;
vector<vector<state>> par;
vector<state> path;

void path_printer(state en)
{
    state cur = en;
    while (cur != make_pair(-1, -1))
    {
        path.push_back(cur);
        cur = par[cur.F][cur.S];
    }

    reverse(path.begin(), path.end());

    for (auto v : path)
    {
        cout << v.F << " " << v.S << endl;
    }
}

bool is_valid(int i, int j)
{
    return i >= 0 && i < n && j >= 0 && j < m && arr[i][j] != '#';
}

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

vector<state> neighbours(state node)
{
    vector<state> ans;
    for (int i = 0; i < 4; i++)
    {
        int x = node.F + dx[i];
        int y = node.S + dy[i];

        if (is_valid(x, y))
            ans.push_back({x, y});
    }

    return ans;
}

void bfs(state st_node)
{
    vis.resize(n, vector<int>(m, 0));
    dis.resize(n, vector<int>(m, INF));
    par.assign(n, vector<state>(m, {-1, -1}));

    queue<state> q;
    q.push(st_node);
    vis[st_node.F][st_node.S] = 1;
    dis[st_node.F][st_node.S] = 0;

    par[st_node.F][st_node.S] = {-1, -1};

    while (!q.empty())
    {
        state node = q.front();
        q.pop();

        for (state v : neighbours(node))
        {
            if (!vis[v.F][v.S])
            {
                vis[v.F][v.S] = 1;
                dis[v.F][v.S] = dis[node.F][node.S] + 1;
                par[v.F][v.S] = node;
                q.push(v);
            }
        }
    }
}

void solve()
{
    cin >> n >> m;
    arr.resize(n);

    state st, en;

    for (int i = 0; i < n; i++)
    {
        arr[i].resize(m);
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];

            if (arr[i][j] == 'S')
                st = {i, j};
            else if (arr[i][j] == 'F')
                en = {i, j};
                
        }
    }

    bfs(st);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << dis[i][j] << "\t";
        }
        cout << endl;
    }

    debug(st);
    debug(en);
    debug(vis);
    debug(dis);
    debug(par);

    if (!vis[en.F][en.S])
        cout << "Finish is not reachable" << endl;
    else
    {
        cout << dis[en.F][en.S] << endl;

        path_printer(en);

        debug(path);

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