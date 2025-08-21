#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

int n, m;
vector<int> heights;
vector<vector<int>> grid;

int largestRectArea_inhistogram()
{
    stack<int> st;
    int maxArea = 0;

    int m = heights.size();

    for (int i = 0; i <= m; i++)
    {
        int currHeight = (i == m) ? 0 : heights[i];

        while (!st.empty() && currHeight < heights[st.top()])
        {
            int height = heights[st.top()];
            st.pop();

            int width;
            if (st.empty())
                width = i;
            else
                width = i - st.top() - 1;

            maxArea = max(maxArea, height * width);
        }
        st.push(i);
    }

    return maxArea;
}

void solve()
{
    cin >> n >> m;
    grid.resize(n, vector<int>(m));
    heights.resize(m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    int maxArea = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
                heights[j]++;
            else
                heights[j] = 0;
        }

        int area = largestRectArea_inhistogram();

        maxArea = max(maxArea, area);
    }

    cout << maxArea << "\n";

    grid.clear();
    heights.clear();
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;

    while (t--)
        solve();

    return 0;
}