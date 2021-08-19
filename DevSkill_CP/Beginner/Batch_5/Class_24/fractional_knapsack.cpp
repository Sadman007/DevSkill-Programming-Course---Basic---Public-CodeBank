#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int>&pa, pair<int, int>&pb) {
    return pa.first * pb.second > pa.second * pb.first;
}

int main() {
    int n, W;
    cin >> n >> W;
    vector<pair<int, int> > items(n);
    for(int i = 0; i < n; i++) {
        cin >> items[i].first >> items[i].second; /// first = price, second = weight.
    }
    sort(items.begin(), items.end(), cmp);
    int remW = W;
    double totalProfit = 0;
    for(int i = 0; i < n; i++) {
        int itemTaken = min(remW, items[i].second);
        totalProfit += 1.0 * (items[i].first / items[i].second) * itemTaken;
        remW -= itemTaken;
        if(remW <= 0) break;
    }
    cout << totalProfit << "\n";
    return 0;
}
