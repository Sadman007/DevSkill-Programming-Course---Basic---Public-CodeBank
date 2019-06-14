#include <bits/stdc++.h>
using namespace std;

int n,arr[1000];
int dp[1000][1000];

int f(int pos,int prvPos)
{
    if(pos>n) return 0;
    if(arr[pos]>arr[prvPos]) return max(1+f(pos+1,pos),f(pos+1,prvPos));
    else return f(pos+1,prvPos);
}

int f_optimized(int pos,int prv)
{
    if(pos>n) return 0;
    if(arr[pos]>prv) return max(1+f(pos+1,arr[pos]),f(pos+1,prv));
    else return f(pos+1,prv);
}

int main()
{
    cin >> n;
    for(int i=1;i<=n;i++) cin >> arr[i];
    cout << f_optimized(1,0) << "\n";
    cout << f(1,0) << "\n";
    return 0;
}
