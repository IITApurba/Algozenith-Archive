#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long
int n;
string s;

int dp[100005][4]; // DP array, dp[i][prev] -> i index tak ka answer jab prev last character ho

int rec(int i, int prev)
{
    // 0->'A', 1->'B', 2->'C', 3->'D'
    
    // Base Case: Agar poora string traverse kar liya to ek valid sequence mil gaya
    if (i == n)
        return 1;
    
    // Cache Check: Agar pehle se computed hai to directly return kar do
    if (prev != -1 && dp[i][prev] != -1)
        return dp[i][prev];
    
    int ans = 0;
    
    if (s[i] == '?') // Agar current character '?' hai to 4 options hain
    {
        for (int ch = 0; ch < 4; ch++)
        {
            if (ch == prev) // Same consecutive character allowed nahi hai
                continue;
            ans += rec(i + 1, ch); // Next index ke liye recursive call
        }
    }
    else // Agar current character fixed hai
    {
        if (s[i] - 'A' == prev) // Agar previous character same hai to ye sequence valid nahi
            return 0;
        else
            ans += rec(i + 1, s[i] - 'A'); // Naya previous character update karke call
    }

    // Save and return
    if (prev != -1)
        dp[i][prev] = ans;
    return ans;
}

void solve()
{
    cin >> n >> s;

    memset(dp, -1, sizeof dp); // DP array initialize kar diya -1 se (taaki cache check kaam kare)
    
    cout << rec(0, -1) << '\n'; // Recursion call kiya starting index se, -1 means koi prev character nahi hai
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