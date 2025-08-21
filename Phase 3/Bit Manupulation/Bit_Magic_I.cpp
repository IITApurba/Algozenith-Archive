
#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

void solve() {
    int q;
    cin >> q;
    ll val = 0;
    while (q--) {
        int t, i;
        cin >> t;
        //t++;
        if (t == 1) {
            cin >> i;
            cout << ((val >> i) & 1) << endl;
        }
        if (t == 2) {
            cin >> i;
            val |= (1LL << i);
        }
        if (t == 3) {
            cin >> i;
            val &= (~(1LL << i));
        }
        if (t == 4) {
            cin >> i;
            val ^= (1LL << i);
        }
        if (t == 5) {
            if (__builtin_popcountll(val) == 60) {
                cout << 1 << endl;
            }
            else {
                cout << 0 << endl;
            }
        }
        if (t == 6) {
            if (__builtin_popcountll(val) >= 1) {
                cout << 1 << endl;
            }
            else {
                cout << 0 << endl;
            }
        }
        if (t == 7) {
            if (__builtin_popcountll(val) == 0) {
                cout << 1 << endl;
            }
            else {
                cout << 0 << endl;
            }
        }
        if (t == 8) {
            cout << __builtin_popcountll(val) << endl;
        }
        if (t == 9) {
            cout << val << endl;
        }
    }
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);


    int t = 1;
    // int i = 1;
    // cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}

