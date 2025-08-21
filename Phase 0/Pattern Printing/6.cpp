#include <bits/stdc++.h>
using namespace std;

// n = 7
// A 
// B C 
// C D E 
// D E F G 
// E F G H I 
// F G H I J K 
// G H I J K L M 

void fun(int i, int j, int n)
{
    if (i >= j)
    {
        cout << char(i + j + 'A') << " ";
    }
}

void solve()
{

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fun(i, j, n);
        }
        cout << endl;
    }
}

int main()
{
    int t = 1;
    // cin >> t;

    while (t--)
        solve();

    return 0;
}