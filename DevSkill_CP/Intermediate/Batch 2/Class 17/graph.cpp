#include <bits/stdc++.h>
using namespace std;

vector<int>adjacency_list[1000]; /// array of vector

int main()
{
    int V,E;
    cin >> V >> E;
    for(int i=0;i<E;i++)
    {
        int a,b;
        cin >> a >> b;
        adjacency_list[a].push_back(b);
        adjacency_list[b].push_back(a);
    }
    for(int i = 1;i<=V;i++)
    {
        printf("%d : ",i);
        for(int j=0;j<adjacency_list[i].size();j++)
        {
            printf("%d ",adjacency_list[i][j]);
        }
        puts("");
    }
    return 0;
}
