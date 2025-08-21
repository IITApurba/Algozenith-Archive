#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Step 1: Calculate the total number of 1's in the array
    int ones = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
        {
            ones++;
        }
    }

    // Step 2: Convert the array for maximum gain calculation
    // Replace 1 -> -1, 0 -> 1
    vector<int> gain(n);
    for (int i = 0; i < n; i++)
    {
        gain[i] = (a[i] == 0) ? 1 : -1;
    }

    // Step 3: Use Kadane's algorithm to find the maximum subarray sum in the gain array
    int max_gain = 0, current_gain = 0;
    for (int i = 0; i < n; i++)
    {
        current_gain += gain[i];
        if (current_gain < 0)
        {
            current_gain = 0;
        }
        max_gain = max(max_gain, current_gain);
    }

    // Step 4: Special case handling
    // If all elements are 1, we must flip one subarray, so the result will be `ones - 1`
    if (ones == n)
    {
        cout << ones - 1 << endl;
    }
    else
    {
        // Otherwise, add the maximum gain to the current number of 1's
        cout << ones + max_gain << endl;
    }
}

int main()
{
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
