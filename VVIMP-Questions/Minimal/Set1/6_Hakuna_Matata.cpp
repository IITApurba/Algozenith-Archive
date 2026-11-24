/*
  Problem : Hakuna Matata
  Link    : https://maang.in/problems/Hakuna-Matata--733
  Given   : n x m grid + k queries: 'r x y' swap rows, 'c x y' swap columns, 'g x y' get cell.
  Find    : The value at cell (x, y) for every 'g' query.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    vector<int> r(n), c(m);
    for (int i = 0; i < n; i++)
    {
        r[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        c[i] = i;
    }
    while (k--)
    {
        char ch;
        int x, y;
        cin >> ch;
        cin >> x >> y;
        x--, y--;
        if (ch == 'g')
        {
            cout << grid[r[x]][c[y]] << endl;
        }
        else if (ch == 'r')
        {
            swap(r[x], r[y]);
        }
        else
        {
            swap(c[x], c[y]);
        }
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