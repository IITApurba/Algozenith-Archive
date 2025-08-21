#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

vector<ii> Factors(long long x)
{
    vector<ii> ans;

    for (long long i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            int cnt = 0;

            while (x % i == 0)
            {
                cnt++;
                x = x / i;
            }
            ans.push_back({i, cnt});
        }
    }
    if (x > 1)
        ans.push_back({x, 1});
    return ans;
}

int main()
{

    int n;
    cin >> n;
    vector<ii> ans = Factors(n);

    for (auto x : ans)
    {
        cout << x.first << " " << x.second << endl;
    }
    cout << endl;

    return 0;
}