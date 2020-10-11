/**

Introduction to Graph

**/

#include <bits/stdc++.h>
using namespace std;

int V,E;
vector<int>adjacencyList[100];

int main()
{
    printf("Enter the number of vertices\n");
    scanf("%d",&V);
    printf("Enter the number of edges\n");
    scanf("%d",&E);

    for(int i=0;i<E;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        adjacencyList[a].push_back(b);
        adjacencyList[b].push_back(a); /// if you want to make the edge directed,comment out this line
    }
    printf("Printing the adjacency list form...\n");
    for(int i=1;i<=V;i++)
    {
        printf("%d : ",i);
        for(int j=0;j<(int)adjacencyList[i].size();j++)
        {
            printf("%d ",adjacencyList[i][j]);
        }
        printf("\n");
    }
    return 0;
}

