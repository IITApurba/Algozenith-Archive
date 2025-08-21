#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long
int n;
string s;

int dp[10][4][4]; // DP array, dp[i][prev][first] -> i index tak ka answer jab prev last character ho aur first starting character ho

int rec(int i, int prev, int first)
{
    // 0->'A', 1->'B', 2->'C', 3->'D'
    // Base Case: Agar poora string traverse kar liya to ek valid sequence mil gaya
    if (i == n)
        if (prev == first && n != 1) // Agar last character first character se match karta hai to ye valid nahi hai
            return 0;
        else
            return 1;

    // Cache Check: Agar pehle se computed hai to directly return kar do
    if (prev != -1 && dp[i][prev][first] != -1)
        return dp[i][prev][first];

    int ans = 0;

    if (s[i] == '?') // Agar current character '?' hai to 4 options hain
    {
        for (int ch = 0; ch < 4; ch++)
        {
            if (ch == prev) // Same consecutive character allowed nahi hai
                continue;
            if (i == 0) // Agar first index hai to first ko update karna padega
                ans += rec(i + 1, ch, ch);
            else
                ans += rec(i + 1, ch, first); // Next index ke liye recursive call
        }
    }
    else // Agar current character fixed hai
    {
        if (s[i] - 'A' == prev) // Agar previous character same hai to ye sequence valid nahi
            return 0;
        else if (i == 0) // Agar first character fix hai to first ko set kar do
            ans += rec(i + 1, s[i] - 'A', s[i] - 'A');
        else
            ans += rec(i + 1, s[i] - 'A', first);
    }

    // Save and return
    if (prev != -1)
        dp[i][prev][first] = ans;
    return ans;
}

void solve()
{
    cin >> n >> s;

    if (n == 1) // Edge case: Agar ek hi character hai
        if (s == "?")
            cout << 4 << '\n'; // '?' ko 'A', 'B', 'C', ya 'D' set kar sakte hain
        else
            cout << 1 << '\n'; // Ek fixed character ke liye sirf ek valid sequence hoga

    memset(dp, -1, sizeof dp); // DP array initialize kar diya -1 se (taaki cache check kaam kare)

    cout << rec(0, -1, -1) << '\n'; // Recursion call kiya starting index se, -1 means koi prev character nahi hai

    debug(dp);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1; // Number of test cases

    while (t--)
        solve();

    return 0;
}
