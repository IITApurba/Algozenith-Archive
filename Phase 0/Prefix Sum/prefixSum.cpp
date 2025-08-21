#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> array = {1, 2, 3, 4, 5};

    vector<int> prefixSum(array.size(), 0);

    prefixSum[0] = array[0];

    for (int i = 1; i < array.size(); i++)
        prefixSum[i] = prefixSum[i - 1] + array[i];

    // print prefix sum
    for (int i = 0; i < prefixSum.size(); i++)
        cout << prefixSum[i] << " ";
    cout << endl;

    int q;
    cout << "Enter number of queries: ";
    cin >> q;

    while (q--)
    {
        int L, R;
        cin >> L >> R;

        int result;

        if (L == 0)
            result = prefixSum[R];
        else
            result = prefixSum[R] - prefixSum[L - 1];

        cout << "Sum of elements from index " << L << " to " << R << " is: " << result << endl;
    }

    return 0;
}