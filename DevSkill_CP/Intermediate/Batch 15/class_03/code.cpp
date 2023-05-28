#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    cin >> q;
    unordered_map<string, int> mp;
    mp["blue"] = 1;
    mp["black"] = 10;
    mp["orange"] = -5;
    mp["violet"] = 0;

    for (auto it : mp)
    {
        cout << it.first << " " << it.second << "\n";
    }
    /// 3 1 4 2

    return 0;
}
