/**
    Tag: Brute Force / Pattern Finding / Number Theory
    Observation: Do bruteforce for 1 to 100 ( say ) and you'll get the pattern.
    The pattern is : Only the square numbers and 2*square numbers have odd number of odd divisors.
**/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll f(ll N)
{
    ll r1 = sqrtl(N);
    ll r2 = sqrtl(N/2);
    return r1 + r2;
}

ll getRangeValue(ll L,ll R)
{
    return f(R) - f(L-1);
}

int main()
{
    int t,cs=1;
    ll L,R;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld",&L,&R);
        printf("Case %d: %lld\n",cs++,getRangeValue(L,R));
    }
    return 0;
}
