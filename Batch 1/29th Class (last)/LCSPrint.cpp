#include <bits/stdc++.h>

using namespace std;

string s1,s2;
int dp[10][10];
int path[10][10];

int f(int n,int m)
{
    if(n<0 || m<0)
        return 0;
    if(dp[n][m]!=-1)
        return dp[n][m];

    if(s1[n]==s2[m])
    {
        path[n][m] = 3;
        return dp[n][m] = 1+f(n-1,m-1);
    }
    else
    {
        int r1 = f(n-1,m);
        int r2 = f(n,m-1);
        if(r1>r2)
            path[n][m] = 1;
        else
            path[n][m] = 2;
        return dp[n][m] = max(r1,r2);
    }
}

void solPrint(int n,int m)
{
    if(n<0 || m<0)
        return;
    if(path[n][m]==3)
    {
        solPrint(n-1,m-1);
        cout << s1[n];
    }
    else if(path[n][m]==1)
    {
        solPrint(n-1,m);
    }
    else if(path[n][m]==2)
    {
        solPrint(n,m-1);
    }
}

int main()
{
    cin >> s1 >> s2;
    memset(dp,-1,sizeof dp);
    int n,m;
    n=s1.size();
    m=s2.size();
    cout << f(n-1,m-1) << endl;
    solPrint(n-1,m-1);
    return 0;
}
