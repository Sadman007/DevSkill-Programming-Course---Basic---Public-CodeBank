#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define MOD 1000000007
#define MAX 200005

int maxCross(int *arr,int L,int M,int R)
{
    int LS,RS,S=0;
    LS = RS = INT_MIN/2;
    for(int i=M;i>=L;i--)
    {
        S+=arr[i];
        if(S>LS) LS = S;
    }
    S = 0;
    for(int i=M+1;i<=R;i++)
    {
        S+=arr[i];
        if(S>RS) RS = S;
    }
    return (LS+RS);
}

int maxSum(int *arr,int L,int R)
{
    if(L==R)
    {
        return arr[L];
    }
    int M = (L+R)/2;
    int maxLeft = maxSum(arr,L,M);
    int maxRight = maxSum(arr,M+1,R);
    int maxSumCross = maxCross(arr,L,M,R);
    return max(maxLeft,max(maxRight,maxSumCross));
}
int main()
{
    int n,ara[1000];
    cin >> n;
    for(int i=0;i<n;i++) cin >> ara[i];
    cout << maxSum(ara,0,n-1) << "\n";
    return 0;
}
