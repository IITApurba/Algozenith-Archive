#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

#define int long long
#define pb push_back
#define endl '\n'
const int mod = 1e9+7;
const long long INF = 1e18;

void init(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int power(int a,int b,int mod){
    int res = 1;
    while(b){
        if(b&1){
            res *= a;
            res %= mod;
        }
        a *= a;
        a %= mod;
        b = (b>>1);
    }
    return (res%mod);
}

void solve(){
	int n;
    cin >> n;

    vector<int> arr(n), pref(31,0);
    for(int i=0;i<n;i++){
        cin >> arr[i];
        for(int j=0;j<31;j++){
            pref[j] += ((arr[i]>>j)&1);
        }
    }

    int xorSum = 0, andSum = 0, subsetXor = 0, subsetAnd = 0;
    for(int i=0;i<31;i++){

        int cntOne = pref[i];
        int cntZero = n-cntOne;

        //  xor Sum
        int temp = (cntOne*cntZero);
        temp %= mod;
        temp *= (1<<i);
        temp %= mod;

        xorSum += temp;
        xorSum %= mod;

        //subset xor sum
        if(cntOne){
            temp = power(2,cntOne-1,mod);
            temp %= mod;
            temp *= power(2,cntZero,mod);
            temp %= mod;
            temp *= (1<<i);
            temp %= mod;
            
            subsetXor += temp;
            subsetXor %= mod;
        }

        //AND sum
        temp = (cntOne*(cntOne-1));
        temp %= mod;
        temp *= power(2,mod-2,mod);
        temp %= mod;
        temp *= (1<<i);
        temp %= mod;

        andSum += temp;
        andSum %= mod;

        //Subset AND sum
        if(cntOne){
            temp = power(2,cntOne,mod)-1;
            temp %= mod;
            temp *= (1<<i);
            temp %= mod;

            subsetAnd += temp;
            subsetAnd %= mod;
        }
    }
    cout << xorSum << " " << subsetXor << " " << andSum << " " << subsetAnd << endl;


    
}

int32_t main(){
	
	init();
	//clock_t time_req;
	//time_req = clock();

	int _t = 1;
	cin >> _t;
	while(_t--)
		solve();

	//time_req = clock() - time_req;
	//cout << endl << "Time Taken is ";
	//cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}