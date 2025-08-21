#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e9
#define F first
#define S second
#define ld long double
#define endl '\n'
const int mod = 1e9 + 7;
// using ll= long long;


void solve() {
    int n, ans = 0;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++)cin >> nums[i];
	vector<int> dp1(n), dp2(n), lis, lds;
	for (int i = 0; i < n; i++) {
		auto it = lower_bound(lis.begin(), lis.end(), nums[i]);
		if (it != lis.end()){
            *it = nums[i];
             dp1[i] = (it - lis.begin()) + 1;
        }
		else{
            lis.push_back(nums[i]);
            dp1[i] = lis.size();
        } 
	}
	for (int i = n - 1; i >= 0; i--) {
		auto it = lower_bound(lds.begin(), lds.end(), nums[i]);
		if (it != lds.end()){
            *it = nums[i];
            dp2[i] = it - lds.begin() + 1;
        }
		else{
            lds.push_back(nums[i]);
            dp2[i] = lds.size();
        }  
		if (dp1[i] >= 2 && dp2[i] >= 2){
            ans = max(ans, dp1[i] + dp2[i] - 1);
        }
	}
	if (ans == 0)cout << -1 << endl;
	else cout << n - ans << endl;
}



signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);

	int _t=1;
		cin>>_t;
	while(_t--) {
		solve();
	}
	return 0;
}