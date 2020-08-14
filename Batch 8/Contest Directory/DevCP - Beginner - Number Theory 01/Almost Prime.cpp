#include <bits/stdc++.h>
using namespace std;


int main()
{
    int ans=0,n;
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
        int num = i;
        int prm_cnt = 0;
        for(int j=2;j*j<=num;j++)
        {
            if(num%j==0)
            {
                prm_cnt++;
                while(num%j==0)
                {
                    num/=j;
                }
            }
        }
        if(num>1) prm_cnt++;
        ans+=(prm_cnt==2);
    }
    printf("%d\n",ans);
	return 0;
}