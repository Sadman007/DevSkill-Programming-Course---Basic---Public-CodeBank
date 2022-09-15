#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000;
vector<int> gr[MAX + 5];

int main()
{
    int v, e, a, b;
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        /// a, b; a -- b
        cin >> a >> b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    for (int n = 0; n < v; n++)
    {
        cout << n << " : ";
        for (auto u : gr[n])
        {
            cout << u << " ";
        }
        cout << "\n";
    }
    return 0;
}
