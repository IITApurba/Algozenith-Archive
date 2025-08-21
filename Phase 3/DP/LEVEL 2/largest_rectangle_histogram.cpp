#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; i++)
        cin >> heights[i];

    stack<int> st;
    int maxArea = 0;

    for (int i = 0; i <= n; i++)
    {
        // Treating imaginary 0 height at the end
        int currHeight = (i == n) ? 0 : heights[i];

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

    cout << maxArea << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;

    while (t--)
        solve();

    return 0;
}
