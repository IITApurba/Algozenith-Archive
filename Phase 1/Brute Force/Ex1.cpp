#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;

typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    // abcde/fghij = n
    // abcde = n*fghij
    vector<pair<int, int>> ans;
    for (int i = 1; i <= 999999; i++)
    {
        int x = i * n;
        if (x > 99999)
            continue;
        else
            ans.push_back({x, i});
    }

    auto it = find(ans.begin(), ans.end(), make_pair(79546, 1283));

    if(it != ans.end())
        cout << it->first << " / " << it->second << endl;
    else
        cout << "Not found" << endl;
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