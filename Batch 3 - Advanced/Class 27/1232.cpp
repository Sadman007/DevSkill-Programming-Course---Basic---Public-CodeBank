#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
#define ll long long
#define MOD 100000007
#define pii pair<int,int>
#define all(v) (v).begin(),(v).end()
int T, n, K, a[101], dp[10001];

int main()
{
    int cs = 1;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &n, &K);
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        for(int i = 0; i <= K; i++) dp[i] = 0;
        dp[0] = 1;
        for(int i = 0; i < n; i++)
        {
            for(int value = a[i]; value <= K; value++)
            {
                dp[value] = (dp[value] + dp[value - a[i]]);
                if(dp[value] >= MOD) dp[value] -= MOD;
            }
        }
        printf("Case %d: %d\n", cs++, dp[K]);
    }
    return 0;
}
