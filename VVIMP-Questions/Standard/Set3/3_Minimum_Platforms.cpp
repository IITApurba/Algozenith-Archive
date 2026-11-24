/*
  Problem : Minimum Platforms
  Link    : https://maang.in/problems/Minimum-Platforms-612
  Given   : N trains with arrival and departure times (same time = conflict).
  Find    : Minimum number of platforms so no train waits.
*/

#include <bits/stdc++.h>
using namespace std;

int MinimumPlatforms(vector<pair<int, int>> &trains)
{
    int n = trains.size();

    vector<int> arrival(n), departure(n);

    for (int i = 0; i < n; i++)
    {
        arrival[i] = trains[i].first;
        departure[i] = trains[i].second;
    }
    
    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());
    
    int platforms_needed = 1, max_platforms = 1;
    int i = 1, j = 0;
    while (i < n && j < n)
    {
        if (arrival[i] <= departure[j])
        {
            platforms_needed++;
            i++;
        }
        else
        {
            platforms_needed--;
            j++;
        }
        max_platforms = max(max_platforms, platforms_needed);
    }


    return max_platforms;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> trains;

    for (int i = 0; i < n; i++)
    {
        int s, t;
        cin >> s >> t;
        trains.push_back({s, t});
    }

    cout << MinimumPlatforms(trains) << '\n';
}