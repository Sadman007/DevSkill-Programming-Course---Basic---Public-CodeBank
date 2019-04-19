/**

Introduction to Graph

**/

#include <bits/stdc++.h>
using namespace std;

int V,E,matrix[100][100];

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
        matrix[a][b] = 1;
        matrix[b][a] = 1; /// if you want to make the edge directed,comment out this line
    }
    printf("Printing the adjacency matrix form...\n");
    for(int i=1;i<=V;i++)
    {
        for(int j=1;j<=V;j++)
        {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}

