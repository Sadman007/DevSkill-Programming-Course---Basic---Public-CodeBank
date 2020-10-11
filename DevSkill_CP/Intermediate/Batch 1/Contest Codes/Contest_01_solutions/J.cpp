#include <bits/stdc++.h>
using namespace std;

map<int,int>mp;
int x,k,type,L,R;

int main()
{
    scanf("%d%d",&x,&k);
    for(int i=1; i<=k; i++)
    {
        scanf("%d",&type);
        if(type==1)
        {
            scanf("%d%d",&L,&R);
            mp[L] = 1;
            mp[R] = 1;
        }
        else
        {
            scanf("%d",&L);
            mp[L] = 1;
        }
    }
    int mx = (x-1)-mp.size();
    int mn = 0;
    for(int i=1; i<x; i++)
    {
        if(mp[i]!=1)
        {
            if(i+1==x)
                mn++;
            else
            {
                if(mp[i+1]!=1)
                {
                    mn++;
                    i++;
                }
                else
                    mn++;
            }
        }
    }
    printf("%d %d\n",mn,mx);
    return 0;
}
