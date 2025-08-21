#include <iostream>
#include <vector>
using namespace std;

long long getProductOfSubarraySums(vector<int> &arr)
{
    int n = arr.size();
    long long product = 1;

    // Calculate sum of all possible subarrays one by one
    for (int i = 0; i < n; i++)
    {
        long long subarraySum = 0;
        for (int j = i; j < n; j++)
        {
            subarraySum += arr[j];
            product *= subarraySum;
        }
    }

    return product;
}

void solve()
{
    vector<int> arr = {1, 2, 3};

    long long result = getProductOfSubarraySums(arr);
    cout << result << endl;
}