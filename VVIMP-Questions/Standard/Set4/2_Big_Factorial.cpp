#include <bits/stdc++.h>
using namespace std;

// big number, digits stored in reverse: ones at index 0, tens at index 1, ...
vector<int> digits;

// multiply the big number by a small x
void multiply(int x)
{
    int carry = 0;

    for (int i = 0; i < digits.size(); i++)
    {
        int prod = digits[i] * x + carry;
        digits[i] = prod % 10; // keep the last digit here
        carry = prod / 10;     // pass the rest forward
    }

    // leftover carry can have several digits (x up to 1000)
    while (carry > 0)
    {
        digits.push_back(carry % 10);
        carry /= 10;
    }
}

void solve()
{
    int n;
    cin >> n;

    digits = {1}; // reset to 1 before starting

    for (int i = 2; i <= n; i++)
        multiply(i);

    // print from most significant digit to least
    for (int i = digits.size() - 1; i >= 0; i--)
        cout << digits[i];
    cout << "\n";
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