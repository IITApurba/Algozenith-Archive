#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;

typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);

    //xor of all elements = sum of all elements/n

    if(n%2 == 1)
        for (int i = 0; i < n; i++)
            a[i] = 1;

    else
    {
        for (int i = 0; i < n; i++)
            a[i] = 2;
        a[0] = 1;
        a[1] = 3;
    }

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << endl;
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}