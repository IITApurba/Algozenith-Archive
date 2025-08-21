#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;

typedef long long ll;

/*
!Notes for the Problem Using Vivek's Recommended Template (CFFTD):
*C (Concept/Topic Used in the Problem)
Weighted inversion count in all subarrays.

*F (Framework, Questions that would lead to new observations or forms)
What is the contribution of each inversion (i, j) to the final answer?
Can we optimize the brute-force approach?

*F (Form, Which style of problem, as discussed in various topics?)
Variation of inversion count with weighted contributions.

*T (Tactics, What macro ideas were used to reduce the time complexity or constraints?)
Brute force approach with O(n^2). Can be optimized using Fenwick Tree or Segment Tree.

*D (Debug, Issues faced, what to keep in mind next time)

Verify the weighting formula (i + 1) * (n - j).
Test edge cases like fully sorted arrays or arrays with duplicates.
*/

void solve()
{
    vector<int> a = {1, 5, 3, 2, 1};
    int n = a.size();

    int inv = 0;

    for (int i = 0; i < n; i++)

        for (int j = i + 1; j < n; j++)

            if (a[i] > a[j])

                inv += (i + 1) * (n - j);

    cout << inv << endl;
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