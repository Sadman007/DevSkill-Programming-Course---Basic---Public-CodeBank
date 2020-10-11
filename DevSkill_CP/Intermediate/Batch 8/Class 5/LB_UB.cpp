#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>vec{1,1,2,5,5,6};
    int LB = lower_bound(vec.begin(), vec.end(), 1) - vec.begin();
    int UB = upper_bound(vec.begin(), vec.end(), 3) - vec.begin();
    cout << "lower bound is " << LB << "\n";
    cout << "upper bound is " << UB << "\n";
    cout << UB - LB << "\n";
    return 0;
}
