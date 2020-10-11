#include <bits/stdc++.h>
using namespace std;

/** direction array **/
int dx[] = {+0,+1,-1,+0};
int dy[] = {+1,+0,+0,-1};
const int MX = 1010;

char grid[MX+5][MX+5];
bool vis[MX+5][MX+5];
int n,m;

bool valid(int x,int y){
    return x>=0 && y>=0 && x<n && y<m && grid[x][y]=='0';
}

void dfs(int x,int y){
    if(!valid(x,y)) return; /// user can accidentally give an invalid src position. So, safety check.
    vis[x][y] = 1;
    grid[x][y] = '*';
    for(int i=0;i<4;i++){
        if(valid(x+dx[i],y+dy[i])) dfs(x+dx[i],y+dy[i]);
    }
}

/**

4 4
0***

0*0*
0*0*
0***

**/

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> grid[i];
    dfs(n/2,m/2); /// start from the center
    for(int i=0;i<n;i++) cout << grid[i] << endl;
    return 0;
}

