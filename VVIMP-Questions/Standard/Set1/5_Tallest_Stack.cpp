#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
vector<tuple<int, int, int>> dimensions;
vector<tuple<int, int, int>> orientations;

int dp[3003];

int rec(int i)
{
    // base case
    if (i == 3 * n)
        return 0;

    // pruning
    if (i > 3 * n)
        return 0;

    // cache check
    if (dp[i] != -1)
        return dp[i];

    // transition

    // base_length = bigger base side, base_bredth = smaller base side

    auto [height, base_length, base_bredth] = orientations[i];

    int ans = height; // option 1: box i alone

    for (int j = 0; j < 3 * n; j++)
    {
        auto [h2, x2, y2] = orientations[j];
        if (x2 < base_length && y2 < base_bredth) // j fits strictly on top of i
            ans = max(ans, height + rec(j));
    }

    // save and return
    return dp[i] = ans;
}

void solve()
{
    cin >> n;
    dimensions.resize(n);

    for (int i = 0; i < n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;

        dimensions[i] = {x, y, z};
    }

    orientations.resize(3 * n);

    for (int i = 0; i < n; i++)
    {
        auto [a, b, c] = dimensions[i];

        // case 1:
        orientations[3 * i] = {a, max(b, c), min(b, c)};
        // case 2:
        orientations[3 * i + 1] = {b, max(a, c), min(a, c)};
        // case 3:
        orientations[3 * i + 2] = {c, max(a, b), min(a, b)};
    }

    memset(dp, -1, sizeof(dp));

    int ans = 0;
    for (int i = 0; i < 3 * n; i++)
        ans = max(ans, rec(i));

    cout << ans << "\n";
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