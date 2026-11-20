#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

vector<vector<int>> combinationSum(int k, int n)
{
    vector<vector<int>> ans;
    vector<int> temp;

    function<void(int, int, int)> rec = [&](int start, int level, int sum)
    {
        if (level == k)
        {
            if (sum == n)
                ans.push_back(temp);
            return;
        }

        if (sum > n || 9 - start + 1 < k - level)
            return;

        for (int i = start; i <= 9; i++)
        {
            if (sum + i > n)
                break;

            temp.push_back(i);
            rec(i + 1, level + 1, sum + i);
            temp.pop_back();
        }
    };

    rec(1, 0, 0);
    return ans;
}


void checker()
{
    int k, n;
    cin >> k >> n;
    vector<int> t;
    auto v = combinationSum(k, n);
    for (auto &x : v)
    {
        sort(x.begin(), x.end());
    }
    sort(v.begin(), v.end());
    for (auto x : v)
    {
        for (auto y : x)
            cout << y << " ";
        cout << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    // int i = 1;
    // cin >> t;
    while (t--)
    {
        // cout << "Case #" << i << ": ";
        checker();
        // i++;
    }
    return 0;
}