#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;

typedef long long ll;

void solve()
{
    vector<int> arr = {1, 2, 3};
    int n = arr.size();

    ll sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i] * (i + 1) * (n - i);
    }

    cout << sum << endl;
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