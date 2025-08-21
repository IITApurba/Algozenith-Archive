vector<ll> a = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1};

bool check(int mid){

    if(a[mid] == 0)
        return false;
    else
        return true;
}

void solve()
{
    int n = a.size();
    int ans = 0;

    int lo = 0, hi = n - 1;

    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;

        if(check(mid)){
            ans = mid;
            hi = mid - 1;
        }
        else{

            lo = mid;
        }
    }

    cout << "The first occurence of 1 is in index " << ans << " " << a[ans] << endl;
}