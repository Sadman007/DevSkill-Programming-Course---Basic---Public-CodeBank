#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007

ll dp[100010][5];
int n;
char s[100010];
/**WRGB**/
unordered_map<char,int>mp;

ll f(int pos,int pr)
{
    if(pos>=n) return 1;
    if(dp[pos][pr]!=-1) return dp[pos][pr];
    ll r = 0;
    if(s[pos]=='W')
    {
        if(s[pos+1]!='R' && pr!=1) r = (r + f(pos+1,1))%M; /// 1 means R
        if(s[pos+1]!='G' && pr!=2) r = (r + f(pos+1,2))%M; /// 2 means G
        if(s[pos+1]!='B' && pr!=3) r = (r + f(pos+1,3))%M; /// 3 means B
    }
    else r = (r + f(pos+1,mp[s[pos]]))%M;
    return dp[pos][pr] = r;
}

int main()
{
    mp['R'] = 1;
    mp['G'] = 2;
    mp['B'] = 3;
    int t,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        n = strlen(s);
        for(int i=0;i<=n;i++) dp[i][0] = dp[i][1] = dp[i][2] = dp[i][3] = -1;
        printf("Case %d: %lld\n",cs++,f(0,0));
    }
    return 0;
}
