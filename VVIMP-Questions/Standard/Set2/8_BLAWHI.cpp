/*
  Problem : BLAWHI
  Link    : https://maang.in/problems/BLAWHI-603
  Given   : N x M chessboard.
  Find    : Ways to place one black + one white knight so they don't attack each other, mod 1e9+7.
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, m;
    cin >> n >> m;

    int mod = 1e9 + 7;

    // all ordered placements of black and white knight
    int cells = n * m;
    int total = cells * (cells - 1);

    // knights attack only when on opposite corners of a 2x3 or 3x2 rectangle
    // number of a x b rectangles = (n - a + 1) * (m - b + 1), clamped at 0
    int rect = max(0LL, n - 1) * max(0LL, m - 2)    // 2x3 rectangles
             + max(0LL, n - 2) * max(0LL, m - 1);   // 3x2 rectangles

    // each rectangle: 2 attacking pairs x 2 (black/white order) = 4
    int ans = (total - 4 * rect) % mod;

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