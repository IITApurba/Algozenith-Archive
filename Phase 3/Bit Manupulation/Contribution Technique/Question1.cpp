#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

string getbitstr(int x)
{
    string cur = "";

    while (x)
    {
        if (x % 2)
            cur += '1';
        else
            cur += '0';
        x /= 2;
    }

    if (cur == "")
        cur = "0";

    reverse(cur.begin(), cur.end());
    return cur;
}

void solve()
{
    // Precomputation
    string s = "";

    int cnt_one = 0;
    int cur_num = 0;

    while (cnt_one <= 100)
    {
        string cur_bits = getbitstr(cur_num);

        int new_one = 0;

        for (auto v : cur_bits)
            if (v == '1')
                new_one++;

        // debug(cur_num, cur_bits, new_one);
        s += cur_bits;
        cnt_one += new_one;

        cur_num++;
    }

    // debug(s);

    vector<int> pos1;

    for (int i = 0; i < s.length(); i++)
        if (s[i] == '1')
            pos1.push_back(i);

    int q;
    cin >> q;

    // Query on precompute

    while (q--)
    {
        int k;
        cin >> k;

        debug(pos1[k - 1]);
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;

    while (t--)
        solve();

    return 0;
}