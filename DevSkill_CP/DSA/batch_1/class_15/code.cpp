#include <bits/stdc++.h>
using namespace std;
#define MAX_NODE 100000
vector<int> adjList[MAX_NODE + 5];

int main()
{
    int n, e, a, b;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b; /// a --- b
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << i << ": ";
        for (int j = 0; j < adjList[i].size(); j++)
        {
            cout << adjList[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
/**
1: 2
2: 1, 3
3: 2
**/
