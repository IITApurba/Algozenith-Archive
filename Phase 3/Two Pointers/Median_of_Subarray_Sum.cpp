#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> prefix(n, 0);
    prefix[0] = a[0];

    for (int i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] + a[i];

    vector<int> subarraySums;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = prefix[j] - (i > 0 ? prefix[i - 1] : 0);
            subarraySums.push_back(sum);
        }
    }

    sort(subarraySums.begin(), subarraySums.end());

    int x = (subarraySums.size() - 1) / 2;

    cout << subarraySums[x] << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}
