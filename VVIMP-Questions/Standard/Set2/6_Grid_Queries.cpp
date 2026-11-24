/*
  Problem : Grid Queries
  Link    : https://maang.in/problems/Grid-Queries-587
  Given   : n x m grid, rows and columns sorted ascending; q queries x.
  Find    : Is x in the grid? (Yes / No), O(1) extra space.
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    int q;
    cin >> q;

    while (q--)
    {
        int x;
        cin >> x;

        // start from the top-right corner
        int row = 0, col = m - 1;
        bool found = false;

        while (row < n && col >= 0)
        {
            if (grid[row][col] == x)
            {
                found = true;
                break;
            }
            else if (grid[row][col] > x)
                col--; // whole column below is even bigger, discard it
            else
                row++; // whole row to the left is even smaller, discard it
        }

        cout << (found ? "Yes" : "No") << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;

    while (t--)
        solve();

    return 0;
}