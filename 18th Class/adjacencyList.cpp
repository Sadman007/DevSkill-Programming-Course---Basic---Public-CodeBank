/**
    Introduction to Graph - DFS
**/

/**
Application of DFS:
1) Detecting cycle in a graph
2) Path Finding
3) SubTree size counting
4) 2D grid visiting (1115 - Filling the Regions)
5) FloodFill
6) Topological Sorting
7) Bipartite testing
8) SCC Finding
9) Puzzle solving
... and many more!
**/

#include <bits/stdc++.h>
using namespace std;

/**
Input:
5 11
00000000000
0****00***0
0*00*00*0*0
0****000000
00000000000

Output:
00000000000
0****00***0
0*SS*00*0*0
0****000000
00000000000

6 10
0020000000
0020111110
2220100010
0000100010
0000111110
0000000000

**/

int n,m;
char grid[10][10];
bool vis[10][10];

bool isValid(int x,int y)
{
    return (grid[x][y]=='0' && x>=0 && y>=0 && x<n && y<m);
}

void floodFill(int x,int y)
{
    if(vis[x][y] == 1) return;
    vis[x][y] = 1;
    if(isValid(x+1,y)) floodFill(x+1,y);
    if(isValid(x-1,y)) floodFill(x-1,y);
    if(isValid(x,y+1)) floodFill(x,y+1);
    if(isValid(x,y-1)) floodFill(x,y-1);
}

int main()
{
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        cin >> grid[i];
    }
    memset(vis,0,sizeof vis);

    floodFill(0,0);
    puts("");

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(vis[i][j]==1) cout << "0";
            else
            {
                if(grid[i][j]=='*') cout << "*";
                else cout << "S";
            }
        }
        cout << "\n";
    }

    return 0;
}

