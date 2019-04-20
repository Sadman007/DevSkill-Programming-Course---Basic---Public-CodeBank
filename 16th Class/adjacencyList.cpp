/**

Introduction to Graph

**/

#include <bits/stdc++.h>
using namespace std;

int V,E;
vector<int>adjacencyList[1000];

void printGraph()
{
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
}

void bfs(int src,int dest)
{
    queue<int>qu;
    bool visited[1000];
    memset(visited,0,sizeof visited);

    int level[1000];

    level[src] = 0;
    qu.push(src);
    visited[src] = 1;

    while(!qu.empty())
    {
        int u = qu.front();
        qu.pop();
        for(int i=0;i<(int)adjacencyList[u].size();i++)
        {
            int v = adjacencyList[u][i];
            if(visited[v]==0)
            {
                visited[v] = 1;
                level[v] = level[u]+1;
                qu.push(v);
            }
        }
    }
    cout << level[src] << " " << level[dest] << "\n";
}

int numberOfTurn(int N,int M)
{
    queue<int>qu;
    bool visited[1000];
    int level[1000];
    memset(visited,0,sizeof visited);

    level[N] = 0;
    qu.push(N);
    visited[N] = 1;

    while(!qu.empty())
    {
        int u = qu.front();
        qu.pop();
        int newNode1 = 2*u;
        int newNode2 = u-1;
        if(newNode1<=2*M)
        {
            if(visited[newNode1]==0)
            {
                visited[newNode1] = 1;
                level[newNode1]=level[u]+1;
                qu.push(newNode1);
            }
        }
        if(newNode2>0)
        {
            if(visited[newNode2]==0)
            {
                visited[newNode2] = 1;
                level[newNode2]=level[u]+1;
                qu.push(newNode2);
            }
        }
    }
    return level[M];
}

/**
    N ---> M
    2 diye gun korte paro
    1 biyog korte paro

    example:
    N = 5
    M = 11
    Ans : 5

    5*2 = 10
    10*2 = 20
    20-1 = 19
    19-1 = 18
    18-1 = 17
    ...
    12-1 = 11

    5-1 = 4
    4-1 = 3
    3*2 = 6
    6*2 = 12
    12-1 = 11

**/


int main()
{
    /*
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

    bfs(1,6);
    */
    cout << numberOfTurn(5,100);

    return 0;
}

