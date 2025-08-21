#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    // Query 1: 64-bit binary representation
    bitset<64> x(n);
    cout << x << endl;

    // Query 2: Position of the most significant bit (MSB)
    if (n == 0) {
        cout << -1 << endl;
    } else {
        cout << 63 - __builtin_clzll(n) << endl;
    }

    // Query 3: Position of the least significant bit (LSB)
    if (n == 0) {
        cout << -1 << endl;
    } else {
        cout << __builtin_ctzll(n) << endl;
    }

    // Query 4: Check if n is a power of 2
    cout << ((n > 0 && (n & (n - 1)) == 0) ? 1 : 0) << endl;

    // Query 5: Largest power of 2 that divides n
    if (n == 0) {
        cout << -1 << endl;
    } else {
        cout << (1LL << __builtin_ctzll(n)) << endl;
    }

    // Query 6: Smallest power of 2 that is not smaller than n
    if (n <= 1) {
        cout << 2 << endl;
    } else {
        cout << (1LL << (64 - __builtin_clzll(n - 1))) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    solve();
    return 0;
}
