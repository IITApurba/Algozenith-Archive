#include <bits/stdc++.h>
using namespace std;

bool isValidSquare(vector<vector<long long>> &v)
{
    // add code here
    bool f = false;
    sort(v.begin(), v.end());
    int n = v.size();
    do
    {
        set<long long> sideLengths;
        for (int i = 0; i < v.size(); i++)
        {
            long long x1 = v[i][0], y1 = v[i][1], x2 = v[(i + 1) % n][0], y2 = v[(i + 1) % n][1];
            long long d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);

            if (d > 0)
                sideLengths.insert(d);
        }
        if (sideLengths.size() == 1)
        {
            set<long long> diagonals;
            for (int i = 0; i < n / 2; i++)
            {
                long long x1 = v[i][0], y1 = v[i][1], x2 = v[n / 2 + i][0], y2 = v[n / 2 + i][1];
                long long d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);

                if (d > 0)
                    diagonals.insert(d);
            }
            if (diagonals.size() == 1)
            {
                f = true;
                break;
            }
        }
    } while (next_permutation(v.begin(), v.end()));
    return f;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<vector<long long>> v(4, vector<long long>(2));
    for (int i = 0; i < 4; i++)
        cin >> v[i][0] >> v[i][1];
    cout << isValidSquare(v) << '\n';
    return 0;
}