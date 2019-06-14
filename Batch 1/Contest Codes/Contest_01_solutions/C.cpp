#include<bits/stdc++.h>
using namespace std;
int s[10010];

int main()
{
    int n,m,d,mid,sum=0;
    scanf("%d%d%d",&n,&m,&d);

    for(int i=0; i<n*m; i++)
        scanf("%d",&s[i]);

    sort(s,s+(n*m)); ///O(NlogN) --> N=n*m
                    /// O(N) --> N=n*m

    mid =s[(n*m)/2];

    for(int i=0; i<n*m; i++)
    {
        if(abs(s[i]-mid)%d!=0)
        {
            printf("-1");
            return 0;
        }
        else
            sum+=(abs(s[i]-mid)/d);
    }
    printf("%d",sum);
    return 0;
}
