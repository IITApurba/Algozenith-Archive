#include <bits/stdc++.h>
using namespace std;

// at most one character may have an odd count
bool canBePalindrome(string &s)
{
    int freq[26] = {0};
    for (char c : s)
        freq[c - 'a']++;

    int odd = 0;
    for (int i = 0; i < 26; i++)
        if (freq[i] % 2 == 1)
            odd++;

    return odd <= 1;
}

void solve()
{
    string s;
    cin >> s;

    if (canBePalindrome(s) == 0)
    {
        cout << -1 << "\n";
        return;
    }

    int n = s.size();
    int l = 0, r = n - 1;
    long long swaps = 0;

    while (l < r)
    {
        // find the matching character for s[l], searching from the right
        int k = r;
        while (k > l && s[k] != s[l])
            k--;

        if (k == l)
        {
            // s[l] is the odd middle char: push it one step right and retry
            swap(s[l], s[l + 1]);
            swaps++;
            continue;
        }

        // bubble s[k] to position r using adjacent swaps
        for (int i = k; i < r; i++)
        {
            swap(s[i], s[i + 1]);
            swaps++;
        }

        // outer pair fixed, move inward
        l++;
        r--;
    }

    cout << swaps << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;

    while (t--)
        solve();

    return 0;
}