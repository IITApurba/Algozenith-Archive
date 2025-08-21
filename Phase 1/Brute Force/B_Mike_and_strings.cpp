#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];

    int len = s[0].size();
    int result = INT_MAX;

    // Rotate each string and match with others
    for (int r = 0; r < len; r++) // r = rotation index
    {
        string target = s[0].substr(r) + s[0].substr(0, r);
        int moves = r; // Moves required to rotate s[0] to the target
        bool possible = true;

        for (int i = 1; i < n; i++)
        {
            string doubled = s[i] + s[i];    // Concatenate s[i] with itself
            auto pos = doubled.find(target); // Find target in doubled string

            if (pos == string::npos)
            {
                possible = false;
                break;
            }
            moves += pos; // Add the rotation moves for s[i]
        }

        if (possible)
            result = min(result, moves); // Minimize total moves
    }

    if (result == INT_MAX)
        cout << -1 << endl; // No solution
    else
        cout << result << endl; // Minimal number of moves
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