#include <bits/stdc++.h>
using namespace std;

string WeekDay(int d, int m, int y)
{
    // Step 1: Treat January and February as months of previous year
    if (m <= 2)
    {
        m += 12;
        y--;
    }

    // Step 2: Divide year into century and year within century
    int yearWithinCentury = y % 100;
    int century = y / 100;

    // Step 3: Apply Zeller's Congruence
    int dayIndex = (d
                    + 13 * (m + 1) / 5
                    + yearWithinCentury
                    + yearWithinCentury / 4
                    + century / 4
                    + 5 * century) % 7;

    // Step 4: Map index to weekday
    string days[] = {
        "Saturday", "Sunday", "Monday", "Tuesday",
        "Wednesday", "Thursday", "Friday"
    };

    return days[dayIndex];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int day, month, year;
    cin >> day >> month >> year;

    cout << WeekDay(day, month, year);
}
