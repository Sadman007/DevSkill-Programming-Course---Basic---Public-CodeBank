#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        long long n,k;
        scanf("%lld %lld",&n,&k);
        long long L=1,R=10000000000LL;
        while(L<R)
        {
            long long mid=L+(R-L+1)/2; // [1, 2] -> mid = 1 -> [1, 2]
            long long baki=mid-(mid/n);
            if(baki==k)
            {
                printf("%lld\n",mid);
                break;
            }
            if(baki>k)
                R=mid-1;
            else
                L=mid;
        }
    }
}
