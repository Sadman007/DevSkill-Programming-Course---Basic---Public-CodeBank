#include <bits/stdc++.h>
using namespace std;
#define MAX 1000006
/// O(V+E)

int arr[100];

int main()
{
    int E,V;
    cin >> V >> E;
    vector<int> graph[V+1];
    for(int i=0;i<E;i++)
    {
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i = 1;i <= V;i++)
    {
        cout << i << " : ";
        for(auto it : graph[i])
        {
            cout << it << " ";
        }
        puts("");
    }
    return 0;
}
