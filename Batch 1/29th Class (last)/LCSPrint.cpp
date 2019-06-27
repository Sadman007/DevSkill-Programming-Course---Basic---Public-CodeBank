#include <bits/stdc++.h>
using namespace std;

string s1,s2;
int dp[1010][1010];
int path[1010][1010];

int f(int a,int b)
{
    if(a<0 or b<0)
        return 0;
    if(dp[a][b]!=-1)
        return dp[a][b];
    if(s1[a] == s2[b])
    {
        path[a][b] = 3;
        return dp[a][b] = 1+f(a-1,b-1);
    }
    else
    {
        ///return dp[a][b] = max(f(a-1,b),f(a,b-1));
        int r1 = f(a-1,b);
        int r2 = f(a,b-1);
        if(r1>r2) path[a][b] = 2;
        else path[a][b] = 1;
        return dp[a][b] = max(r1,r2);
    }
}


void printResult(int a,int b)
{
    if(a<0 || b<0) return;
    if(path[a][b] == 3)
    {
        printResult(a-1,b-1);
        cout << s1[a];
    }
    else if(path[a][b] == 2)
    {
        printResult(a-1,b);
    }
    else if(path[a][b] == 1)
    {
        printResult(a,b-1);
    }
}

int main()
{
    cin >> s1 >> s2;
    int n,m;
    n = s1.size();
    m = s2.size();
    memset(dp,-1,sizeof dp);
    cout << f(n-1,m-1) << "\n";
    printResult(n-1,m-1);
    return 0;
}
