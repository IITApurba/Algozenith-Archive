#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> cnt(1001, 0); // cnt[v] = total boxes with v vials

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        cnt[y] += x; // same y wale saare boxes ek bucket me
    }

    int ans = 0, rem = m;

    // bucket 1000 se neeche: sabse zyada vials pehle
    for (int v = 1000; v >= 1 && rem > 0; v--)
    {
        int take = min(cnt[v], rem);
        ans += take * v;
        rem -= take;
    }

    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}