#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 200002
char str[MAX*10];
int n,k,cnt[MAX*10];
int main()
{
    scanf("%d%s",&k,str);
    ll res = 0;
    n = strlen(str);
    int csum = 0;
    cnt[csum]++;
    for(int i=0; i<n; i++)
    {
        csum+=str[i]=='1';
        int nsum = csum-k;
        if(nsum>=0)
        {
            res+=cnt[nsum];
        }
        cnt[csum]++;
    }
    printf("%lld\n",res);
    return 0;
}
