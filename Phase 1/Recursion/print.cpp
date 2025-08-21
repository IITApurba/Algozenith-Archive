#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;

typedef long long ll;

// Print N -> 1 -> N
void rec(int n)
{
    if(n == 1) {
        cout << n << " ";
        return;
    }
    cout << n << " ";
    rec(n-1);
    cout << n << " ";
}

void solve()
{
    int n;
    cin >> n;

    // Print N - > 1 - > N

    rec(n);
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    while (t--)
        solve();

    return 0;
}