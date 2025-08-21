#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;

vector<int> queens;

void printer()
{
    cout << "Queens" << " : ";
    for (auto v : queens)
        cout << v << " ";
    cout << endl;
}

bool is_valid(int row, int col)
{
    for (int prow = 0; prow < row; prow++)
    {
        int pcol = queens[prow];

        if(pcol == col || abs(col-pcol) == abs(row-prow))
            return 0;
    }

    return 1;
}

void rec(int level)
{
    // base case
    if (level == n)
    {
        printer();
        return;
    }

    // recursive case
    for (int col = 0; col < n; col++)
    {
        // choices
        if (is_valid(level, col))
        {
            // check
            //  move
            queens.push_back(col);
            rec(level + 1);
            queens.pop_back();
        }
    }
}

void solve()
{
    cin >> n;
    rec(0);
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