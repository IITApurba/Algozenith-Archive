/*
  Problem : Super Frequent Number
  Link    : https://maang.in/problems/Super-Frequent-Number-591
  Given   : Array of n integers.
  Find    : Element appearing more than floor(n/2) times, O(n) time, O(1) space.
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int candidate = 0;  // current "winner"
    int count = 0;      // unmatched copies of candidate

    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            // no one is winning, so the current number becomes the candidate
            candidate = v[i];
            count = 1;
        }
        else if (v[i] == candidate)
            count++;    // same number: one more vote
        else
            count--;    // different number: cancels one copy
    }

    // majority is guaranteed to exist, so no verification pass needed
    cout << candidate << "\n";
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