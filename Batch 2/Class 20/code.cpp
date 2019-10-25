#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long
#define BASE 31
#define MAX 1000005
int len;
char str[MAX];
char sub[MAX];
ll power[MAX];
ll H[MAX];
void pre()
{
    power[0]=1;
    for(register int i=1;i<MAX;i++)
        power[i]=(power[i-1]*BASE)%MOD;
}
void hash_generate()
{
    H[0]=str[0]-'0';
    for(register int i=1;i<len;i++)
    {
        H[i]=(H[i-1]*BASE+(str[i]-'0'))%MOD;
    }
}
ll gethash(int L,int R)
{
    if(!L) return H[R]%MOD;
    return ((H[R]%MOD)-((H[L-1]*power[R-L+1])%MOD)+(1LL*MOD*MOD))%MOD;
}
ll convToint()
{
    ll temp = 0;
    int L = strlen(sub);
    for(register int i=0;i<L;i++)
        temp = (temp*BASE + (sub[i]- '0'))%MOD;
    return temp;
}
int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    int t, c=0;
    pre();
    ///freopen("in.txt","r",stdin);
    cin>>t;

    while(t--)
    {
        c++;
        int flag=0;
        cin>>sub>>str;
        len=strlen(str);
        hash_generate();
        int len_2= strlen(sub);
        ll temp = convToint();

        for(register int i=0;i+len_2-1<len;i++)
        {
            if((gethash(i,i+len_2-1))==temp)
            {
                flag++;
            }
        }
        cout << flag << "\n";

    }
}
