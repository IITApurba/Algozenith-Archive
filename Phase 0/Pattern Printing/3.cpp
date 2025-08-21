#include <bits/stdc++.h>
using namespace std;

//             *
//           * * *
//         * * * * *
//       * * * * * * *
//     * * * * * * * * *
//   * * * * * * * * * * *
// * * * * * * * * * * * * *

// * * * * * * * * * * * * *
//   * * * * * * * * * * *
//     * * * * * * * * *
//       * * * * * * *
//         * * * * *
//           * * *
//             *

void fun1(int i, int j, int n)
{
    if (i + j >= n - 1 && i - j >= -(n - 1))
        cout << "* ";
    else
        cout << "  ";
}

void fun2(int i, int j, int n)
{
    if (i + j <= 2 * (n - 1) && i - j <= 0)
        cout << "* ";
    else
        cout << "  ";
}

signed main()
{
    int n = 7; // Height of the pyramid

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 * n - 1; j++)
        {
            fun1(i, j, n);
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 * n - 1; j++)
        {
            fun2(i, j, n);
        }
        cout << endl;
    }

    return 0;
}