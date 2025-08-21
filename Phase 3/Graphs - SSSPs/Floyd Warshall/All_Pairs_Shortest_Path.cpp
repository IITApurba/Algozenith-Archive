// Write your code here
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    long long int dis[n + 1][n + 1];
    int r[n + 1];
    vector<long long int> ans;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> dis[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
        cin >> r[i];

    for (int k = n; k > 0; k--)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dis[i][j] = min(dis[i][j], dis[i][r[k]] + dis[r[k]][j]);
            }
        }
        long long int temp = 0;
        for (int i = k; i <= n; i++)
        {
            for (int j = k; j <= n; j++)
            {
                temp += dis[r[i]][r[j]];
            }
        }
        ans.push_back(temp);
    }
    for (int i = n - 1; i >= 0; i--)
        cout << ans[i] << " ";
}