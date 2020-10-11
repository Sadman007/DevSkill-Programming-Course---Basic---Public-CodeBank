#include <bits/stdc++.h>
using namespace std;
#define MAX 1000006
#define ll long long
#define MOD 1000000007
#define sc(n) scanf("%d",&n)
#define pr(n) printf("%d\n",n)
#define NL puts("")

int getTrailCount(ll n) /// O(log5N)
{
    int fiveCount = 0;;
    ll base = 5
    while(n>0)
    {
        fiveCount+=(n/base);
        if(n<base) break;
        base*=5;
    }
    return fiveCount;
}

int main()
{
    for(int i=1;i<=100;i++)
        cout << i << " : " << getTrailCount(i) << endl;
    return 0;
}
