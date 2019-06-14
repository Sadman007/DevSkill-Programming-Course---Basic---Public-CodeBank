#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long

ll nCr[5000][5000];

ll f(int n,int r)
{
    if(n==r or r==0) return 1;
    if(nCr[n][r]!=-1) return nCr[n][r]%MOD; // this line indicates that we have already calculated the value of f(n,r). So no need to calculate again.
    return nCr[n][r] = (f(n-1,r-1)%MOD+f(n-1,r)%MOD)%MOD;
}

int main()
{
    memset(nCr,-1,sizeof(nCr)); // 
    cout << f(5,2) << "\n";
    return 0;
}