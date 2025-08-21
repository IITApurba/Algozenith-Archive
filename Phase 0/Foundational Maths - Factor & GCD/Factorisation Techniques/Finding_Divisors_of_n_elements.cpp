#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100100;
vector<int> ans[MAXN];

// Precompute divisors up to 1000
void Divisors()
{
    for (int i = 1; i <= 1000; ++i)
    {
        for (int j = i; j <= 1000; j += i)
        {
            ans[j].push_back(i);
        }
    }
}

// Function to find divisors of elements using precomputed values
vector<int> findDivisorsOfElements(const vector<int> &elements)
{
    vector<int> result;

    for (int num : elements)
    {
        // Append precomputed divisors
        result.insert(result.end(), ans[num].begin(), ans[num].end());
    }

    return result;
}

int main()
{
    Divisors(); // Precompute divisors

    vector<int> elements = {12, 25, 1000};
    vector<int> divisors = findDivisorsOfElements(elements);

    for (int d : divisors)
    {
        cout << d << " ";
    }
    cout << endl;

    return 0;
}
