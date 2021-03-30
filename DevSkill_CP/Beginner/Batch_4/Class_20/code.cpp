#include <bits/stdc++.h>
using namespace std;
pair<int, int> info[100005];

/// Fractional Knapsack - Greedy

bool cmp(pair<int, int>& a, pair<int, int>& b)
{
   return (a.first * b.second > b.first * a.second);
}

int main()
{
    int n, W;
    cin >> W >> n;
    for(int i = 0; i < n; i++)
        cin >> info[i].first; /// value
    for(int i = 0; i < n; i++)
        cin >> info[i].second; /// weight

    sort(info, info + n, cmp);

    double totalGain = 0.0;
    for(int i = 0; i < n && W > 0; i++)
    {
        if(W >= info[i].second) /// puratai nite parbo!
        {
            totalGain += info[i].first;
            W -= info[i].second;
        }
        else /// W = 5, info[i].second = 9
        {
            totalGain += (1.00 * info[i].first / info[i].second) * (W);
            W = 0;
        }
    }
    cout << totalGain << "\n";
    return 0;
}
