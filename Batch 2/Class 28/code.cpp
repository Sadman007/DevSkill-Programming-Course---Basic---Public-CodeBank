#include <bits/stdc++.h>
using namespace std;
#define MAX 1000006
#define ll long long
#define MOD 1000000007
#define sc(n) scanf("%d",&n)
#define pr(n) printf("%d\n",n)
#define NL puts("")

int N, targetS, arr[20];

int checkSum(int num) /// it returns the subset sum represented by the set bits of "num"
{
    int sum = 0;
    for(int i=0;i<N;i++)
    {
        if(num&(1<<i)) sum+=arr[i];
    }
    return sum;
}

int main()
{
    cin >> N >> targetS;

    for(int i=0; i<N; i++)
    {
        cin >> arr[i];
    }

    int total_subset = 1 << N; /// 2^N

    int ans = 0;

    for(int i=0; i<total_subset; i++)
    {
        if(checkSum(i) == targetS) ans++;
    }

    cout << ans << endl;

    return 0;
}
