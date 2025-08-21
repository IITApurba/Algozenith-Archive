#include <bits/stdc++.h>
using namespace std;

set<int> divisors_set(int n)
{
    set<int> divisors;

    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {

            divisors.insert(i);
            divisors.insert(n / i);
        }
    }

    return divisors;
}

vector<int> divisors_vector(int n)
{
    vector<int> divisors2;

    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (n / i == i)
            {
                divisors2.push_back(i);
            }
            else
            {
                divisors2.push_back(i);
                divisors2.push_back(n / i);
            }
        }
    }

    return divisors2;
}

int main()
{

    int n;
    cin >> n;

    set<int> divisors;

    divisors = divisors_set(n);

    for (int x : divisors)
    {
        cout << x << " ";
    }

    cout << endl;

    vector<int> divisors2;

    divisors2 = divisors_vector(n);

    for (int x : divisors2)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}