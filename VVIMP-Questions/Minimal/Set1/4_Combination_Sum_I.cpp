#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'


vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    // write code here.
}






















void checker() {
    int n, x, target;
    cin >> n >> target;
    vector<int> t;
    for (int i = 0; i < n; i++) {
        cin >> x;
        t.push_back(x);
    }
    auto v = combinationSum(t, target);
    for (auto &x : v) {
        sort(x.begin(), x.end());
    }
    sort(v.begin(), v.end());
    for (auto x : v) {
        for (auto y : x)cout << y << " ";
        cout << endl;
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
        checker();
        // i++;
    }
    return 0;
}
