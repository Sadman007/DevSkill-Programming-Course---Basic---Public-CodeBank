#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        vector<int> vc(3);
        for (int i = 0; i < 3; i++)
        {
            cin >> vc[i];
        }
        sort(vc.begin(), vc.end()); /// O(NlogN)
        cout << vc[1] << "\n";
    }
    return 0;
}
