#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;

typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int i = 0, j = n - 1;
    int ans = 0;
    while (i < j)
    {
        ans = max(ans, min(a[i], a[j]) * (j - i));
        if (a[i] < a[j])
            i++;
        else
            j--;
    }
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