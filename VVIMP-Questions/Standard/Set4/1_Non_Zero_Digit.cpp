#include <bits/stdc++.h>
using namespace std;

#define int long long

// removes all factors of p from x and returns how many were removed
// e.g. x = 40, p = 2  ->  x becomes 5, returns 3  (40 = 2^3 * 5)
int stripFactor(int &x, int p)
{
    int count = 0;
    while (x % p == 0)
    {
        count++;
        x /= p;
    }
    return count;
}

// last digit of 2^k (k >= 1): cycles 2, 4, 8, 6
// k%4 = 1 -> 2,  2 -> 4,  3 -> 8,  0 -> 6
int lastDigitPow2(int k)
{
    int cycle[4] = {6, 2, 4, 8};
    return cycle[k % 4];
}

void solve()
{
    int n;
    cin >> n;

    int cnt_2 = 0, cnt_5 = 0;   // total factors of 2 and 5 in the product
    int ans = 1;                // last digit of the product without any 2s and 5s
    bool has_zero = false;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        // a single 0 makes the whole product 0
        if (x == 0)
        {
            has_zero = true;
            continue;
        }

        // pull out all 2s and 5s
        cnt_2 += stripFactor(x, 2);
        cnt_5 += stripFactor(x, 5);

        // x is now coprime to 10, so multiplying mod 10 is safe
        ans = ans * (x % 10) % 10;
    }

    if (has_zero)
    {
        cout << -1 << "\n";
        return;
    }

    // every (2, 5) pair makes a trailing zero, so drop them
    int pairs = min(cnt_2, cnt_5);
    int left_2 = cnt_2 - pairs;
    int left_5 = cnt_5 - pairs;

    // put the unpaired factors back
    if (left_5 > 0)
        ans = 5;                                    // odd * 5^k always ends in 5
    else if (left_2 > 0)
        ans = ans * lastDigitPow2(left_2) % 10;     // multiply by 2^left_2

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