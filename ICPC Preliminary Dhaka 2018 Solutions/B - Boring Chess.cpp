/**
    Tag: Brute Force
**/

#include <bits/stdc++.h>
using namespace std;
#define DIM 8

int dx[] = {-1,-2,-1,-2,+1,+2,+1,+2};
int dy[] = {-2,-1,+2,+1,-2,-1,+2,+1};

bool isValid(int x,int y)
{
    return x>=0 && y>=0 && x<DIM && y<DIM;
}

int solve(int n,int m)
{
    int cnt = 0;
    for(int i=0;i<8;i++) cnt+=isValid(n+dx[i],m+dy[i]);
    return cnt;
}

int main()
{
    int n,m,t,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        printf("Case %d: %d\n",cs++,solve(n-1,m-1));
    }
    return 0;
}
