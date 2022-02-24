#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int>&pa, pair<int, int>&pb) {
    return pa.second < pb.second;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int> > tasks(n);
    for(int i = 0; i < n; i++) {
        cin >> tasks[i].first >> tasks[i].second;
    }
    sort(tasks.begin(), tasks.end(), cmp);
    int task_count = 0;
    int prev_end = INT_MIN / 2;
    for(int i = 1; i < n; i++) {
        if(tasks[i].first >= prev_end) {
            task_count++;
            prev_end = tasks[i].second;
        }
    }
    cout << task_count << endl;
    return 0;
}

/**
    ------
        ------
**/
