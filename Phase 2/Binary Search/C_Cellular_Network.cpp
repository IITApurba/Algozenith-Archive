#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, m, k;

bool check(int mid, vector<ll> &cities, vector<ll> &tower)
{
    ll towerPlanted = 0;
    ll lastTowerCoveredTill = -1e18;
    for (ll i = 0; i < n; i++)
    {
        if (lastTowerCoveredTill >= cities[i])
            continue;

        ll lo = cities[i] - mid, hi = cities[i] + mid;

        auto itr = upper_bound(tower.begin(), tower.end(), hi);

        if (itr == tower.begin())
            return 0;
        else
        {
            itr--;
            if (lo <= *itr)
            {
                towerPlanted++;
                lastTowerCoveredTill = (*itr) + mid;
            }
            else
                return false;
        }
    }

    if (towerPlanted > k)
        return false;
    else
        return true;
}

void solve()
{
    cin >> n >> m >> k;

    vector<ll> cities(n), tower(m);
    for (int i = 0; i < n; i++)
        cin >> cities[i];
    for (int i = 0; i < m; i++) // Fix: Read 'm' values instead of 'n'
        cin >> tower[i];

    sort(tower.begin(), tower.end()); // Ensure tower positions are sorted

    ll ans = 0;
    ll lo = 0, hi = 2e9;

    while (lo <= hi)
    {
        ll mid = lo + (hi - lo) / 2; // Avoid potential overflow

        if (check(mid, cities, tower))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }

    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}
