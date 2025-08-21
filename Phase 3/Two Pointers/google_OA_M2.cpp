#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;

typedef long long ll;
#define ff first
#define ss second

void solve()
{
    int n, m;
    cin >> n >> m;

    int arr[n][m];

    set<pair<int, pair<int, int>>> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
        sort(arr[i], arr[i] + m);

        st.insert({arr[i][0], {i, 0}});
    }

    int best = INT_MAX;

    while (1)
    {
        best = min(best, st.rbegin()->first - st.begin()->first);

        auto it = st.begin();
        auto cur = *it;
        st.erase(it);

        if (cur.second.second + 1 < m)
        {
            st.insert({arr[cur.ss.ff][cur.ss.ff + 1], {cur.ss.ff, cur.ss.ss + 1}});
        }
        else
        {
            break;
        }
    }

    cout << "Best: " << best << endl;
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