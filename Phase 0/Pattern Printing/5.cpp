#include <bits/stdc++.h>
using namespace std;

// Print Circle

void fun(int i, int j, int n)
{
    int r = n / 2;

    if ((i - r) * (i - r) + (j - r) * (j - r) == r * r)
        cout << "*";
    else
        cout << " ";
}

int main()
{

    int n;
    cin >> n;

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            fun(i, j, n);
        }
        cout << endl;
    }

    return 0;
}