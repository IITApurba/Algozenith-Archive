#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, k;
    cin >> n >> k;

    // survivor = 0-indexed position of the survivor
    // with 1 person, they are at position 0
    int survivor = 0;

    // grow the circle from 2 people up to n people
    for (int people = 2; people <= n; people++)
        survivor = (survivor + k) % people;

    // convert to 1-indexed
    cout << survivor + 1 << "\n";
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