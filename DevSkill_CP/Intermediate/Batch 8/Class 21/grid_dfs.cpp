#include <bits/stdc++.h>
using namespace std;

bool vis[100][100];
int grid[100][100];
int dx[] = {+0,+1,+0,-1};
int dy[] = {-1,+0,+1,+0};
int n, m;

void dfs(int x, int y)
{
    vis[x][y] = 1;
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny] && grid[nx][ny] != -1)
        {
            dfs(nx, ny);
        }
    }
}

int main()
{
    cin >> n >> m;
    int sx,sy,ex,ey;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if(grid[i][j] == 1)
            {
                sx = i;
                sy = j;
            }
            else if(grid[i][j] == 2)
            {
                ex = i;
                ey = j;
            }
        }
    }
    dfs(sx, sy);
    cout << vis[ex][ey] << "\n";
    return 0;
}
