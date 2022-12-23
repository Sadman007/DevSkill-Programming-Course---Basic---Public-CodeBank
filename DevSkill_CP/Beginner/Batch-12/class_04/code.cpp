#include <bits/stdc++.h>
using namespace std;
/// amortized
int main()
{
    vector<long long> vc; // vector is a dynamic array
    vc.push_back(1);
    vc.push_back(2);
    vc.push_back(5);
    vc.push_back(-5);
    vc.push_back(0);
    sort(vc.begin(), vc.end());
    reverse(vc.begin(), vc.end());
    random_shuffle(vc.begin(), vc.end());

    cout << "size: " << vc.size() << "\n";
    for (int i = 0; i < vc.size(); i++)
    {
        auto elem = vc[i];
        cout << elem << " ";
    }
    cout << "\n";
    for (auto elem : vc)
    {
        cout << elem << " ";
    }
    cout << "\n";
    return 0;
}
