
#include <bits/stdc++.h>
using namespace std;


#define ll int64_t
int dp[101][100010];
int n;
int rec(int ind,int sum,vector<int> &a){
    //prunning
    if(sum<0) return 0;
    //base case
    if(ind==n){
        if(sum==0) return 1;
        else return 0;
    }
    // cache
    if(dp[ind][sum]!=-1) return dp[ind][sum];
    //compute
    int ans = 0;
    ans = rec(ind+1,sum,a)+rec(ind+1,sum-a[ind],a);
    if(ans>=1) ans = 1;
    // save and return
    return dp[ind][sum]= ans;
}

void get_indices(int ind,int sum,vector<int> &p,vector<int> &a){
    //base case
    if(ind==n){
        return;
    }
    //compute
    if(rec(ind+1,sum,a)){
        get_indices(ind+1,sum,p,a);
    }
    else if(rec(ind+1,sum-a[ind],a)){
        p.push_back(ind);
        get_indices(ind+1,sum-a[ind],p,a);
    }
}

vector<vector<int>> subset_queries(vector<int> &arr, vector<int> &queries) {
    int q = queries.size();
    n= arr.size();
    vector<vector<int>> ans(q);
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<q;i++){
        int possible = rec(0,queries[i],arr);
        vector<int> print;
        if(possible){
        get_indices(0,queries[i],print,arr);
        
        ans[i] = print;
        }
        else ans[i] = {-1};
    }
    return ans;
}


void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)cin >> arr[i];
    vector<int> queries(Q);
    for (int i = 0; i < Q; i++)cin >> queries[i];
    auto ans = subset_queries(arr, queries);

    // checker.
    if (ans.size() != Q) {
        cout << 101 << endl;
        return;
    }
    for (int i = 0; i < Q; i++) {
        auto x = ans[i];
        if (x.size() == 0) {
            cout << 101 << endl;
            continue;
        }
        if (x.size() == 1 && x[0] == -1) {
            cout << -1 << endl;
            continue;
        }
        ll sum = 0, p = -10;
        for (auto y : x) {
            if (y < 0 || y >= N || p >= y ) { // valid 0-indexed.
                sum = -1111;
                break;
            }
            p = y;
            sum += arr[y];
        }
        if (sum == queries[i]) {
            cout << 1 << endl;
        }
        else cout << 101 << endl;
    }
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#endif
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
