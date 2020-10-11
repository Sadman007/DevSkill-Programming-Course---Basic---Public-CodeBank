#include <bits/stdc++.h>
using namespace std;
#define MAX 100000

int n,l;
int ara[1100];

int main()
{
    scanf("%d%d",&n,&l);

    for(int i=0;i<n;i++) scanf("%d",&ara[i]);

    sort(ara,ara+n);

    double res = max(ara[0],l-ara[n-1]);

    for(int i=0;i<n-1;i++)
    {
        res = max(res,(double)(ara[i+1]-ara[i])*0.5);
    }
    printf("%.9f\n",res);
    return 0;
}
/**
2D array :
int grid[3][3];
for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
        cin >> grid[i][j];
**/
