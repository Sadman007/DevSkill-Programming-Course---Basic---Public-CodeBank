#include <bits/stdc++.h>
using namespace std;

/// task scheduling
bool cmp(pair<int, int>&a, pair<int, int>&b)
{
    return a.second < b.second;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int> > tasks(n);
    for(int i = 0; i < n; i++)
    {
        cin >> tasks[i].first >> tasks[i].second;
    }
    sort(tasks.begin(), tasks.end(), cmp);

    int task_count = 0;
    pair<int, int> prv = {INT_MAX, INT_MIN};

    for(int i = 0; i < n; i++)
    {
        if(prv.second <= tasks[i].first)
        {
            task_count++;
            prv = tasks[i];
        }
    }
    cout << task_count << "\n";
    return 0;
}
