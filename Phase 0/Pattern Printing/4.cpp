#include <bits/stdc++.h>
using namespace std;

// Repeat: Find monomer and repeat

// _ _ _ _ * _ _ _ _ _ _ _ * _ _ _ _ _ _ _ * _ _ _ _
// _ _ _ * _ * _ _ _ _ _ * _ * _ _ _ _ _ * _ * _ _ _
// _ _ * _ _ _ * _ _ _ * _ _ _ * _ _ _ * _ _ _ * _ _
// _ * _ _ _ _ _ * _ * _ _ _ _ _ * _ * _ _ _ _ _ * _
// * _ _ _ _ _ _ _ * _ _ _ _ _ _ _ * _ _ _ _ _ _ _ *

void fun1(int i, int j, int n)
{
    int sizeOfRepeat = 2 * (n - 1);

    if (i + j % sizeOfRepeat == n - 1 || i - j % sizeOfRepeat == -(n - 1))
    {
        cout << "* ";
    }
    else
        cout << "_ ";
}

// _ _ _ _ * _ _ _ _
// _ _ _ * _ * _ _ _
// _ _ * _ _ _ * _ _
// _ * _ _ _ _ _ * _
// * _ _ _ _ _ _ _ *
// _ _ _ _ * _ _ _ _
// _ _ _ * _ * _ _ _
// _ _ * _ _ _ * _ _
// _ * _ _ _ _ _ * _
// * _ _ _ _ _ _ _ *
// _ _ _ _ * _ _ _ _
// _ _ _ * _ * _ _ _
// _ _ * _ _ _ * _ _
// _ * _ _ _ _ _ * _
// * _ _ _ _ _ _ _ *

void fun2(int i, int j, int n)
{
    int sizeOfRepeat = n;

    if (i % sizeOfRepeat + j == n - 1 || i % sizeOfRepeat - j == -(n - 1))
    {
        cout << "* ";
    }
    else
        cout << "_ ";
}

signed main()
{
    int n; // Height of the monomer
    cin >> n;
    int m; // Number of monomer
    cin >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (2 * (n - 1) * m) + 1; j++)
        {
            fun1(i, j, n);
        }
        cout << endl;
    }

    cout << endl;

    for (int i = 0; i < n * m; i++)
    {
        for (int j = 0; j < 2 * n - 1; j++)
        {
            fun2(i, j, n);
        }
        cout << endl;
    }

    cout << endl;

    return 0;
}