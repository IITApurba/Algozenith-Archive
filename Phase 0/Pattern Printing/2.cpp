#include <bits/stdc++.h>
using namespace std;

//         *
//       *   *       
//     *       *     
//   *           *   
// *               * 

void fun(int i, int j, int n)
{
    if (i +j == n-1 || i-j == -(n-1))
        cout << "* ";
    else
        cout << "  ";
}

int main()
{

    int n = 5;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2*n-1; j++)
        {
            fun(i, j, n);
        }
        cout << endl;
    }

    return 0;
}