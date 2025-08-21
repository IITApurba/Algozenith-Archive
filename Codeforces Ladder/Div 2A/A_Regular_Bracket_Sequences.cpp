#include <iostream>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        // Print i pairs of "()"
        for (int j = 0; j < i; ++j)
            cout << "()";
        // Print (n - i) opening parentheses
        for (int j = 0; j < n - i; ++j)
            cout << "(";
        // Print (n - i) closing parentheses
        for (int j = 0; j < n - i; ++j)
            cout << ")";
        cout << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}