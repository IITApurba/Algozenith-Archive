#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, d;

string cur;

void printer()
{
    cout << "Bracket" << " : ";
    cout << cur;
    cout << endl;
}

// LCCM Framework
void rec(int level, int depth)
{
    // level = index
    cout << "DEB: " << level << " " << cur << endl;
    if (level == n)
    {
        if (depth == 0)
            cout << cur << endl;

        return;
    }

    // '('
    {
        if (depth + 1 <= d)
        {
            cur += '(';
            rec(level + 1, depth + 1);
            cur.pop_back();
        }
    }
    //')'
    {
        if (depth - 1 >= 0)
        {
            cur += ')';
            rec(level + 1, depth - 1);
            cur.pop_back();
        }
    }
}

void solve()
{
    cin >> n >> d;
    rec(0, 0);
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