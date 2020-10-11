#include <bits/stdc++.h>
using namespace std;
#define MAX 100005
bool is_prime[MAX+10];
vector <int> prime;
vector<long long> vec[10001];

void sieve()
{
    is_prime[1]=1;
    for(int i=2; i*i <= MAX; i++)
    {
        if(is_prime[i]==0)
        {
            for(int j=i*i; j<=MAX; j +=i )
            {
                is_prime[j]=1;
            }
        }
    }
    for(int i = 2; i <= MAX; i++)
    {
        if(is_prime[i] == 0)
            prime.push_back(i);
    }
}

int div_count(int n)
{
    int total = 1;
    for(int i=0; prime[i]*prime[i] <= n; i++)
    {
        if(n%prime[i] == 0)
        {
            int count = 0;
            while(n%prime[i]==0)
            {
                n /=prime[i];
                count++;
            }
            total *= ((2*count)+1);
        }
    }
    if(n!=1)
    {
        total*=3;
    }
	return total;
}

int main()
{
	sieve();
    long long low,high,k;
    for(int i=1; i<=MAX; i++)
    {
        vec[div_count(i)].push_back(1LL * i * i);
    }
    int UB, LB, cs;
    scanf("%d", &cs);
    while(cs--)
    {
        scanf("%lld %lld %lld", &k, &low, &high);
        UB = upper_bound(vec[k].begin(),vec[k].end(),high) - vec[k].begin() ;
        LB = lower_bound(vec[k].begin(),vec[k].end(),low)- vec[k].begin() ;
        printf("%d\n", UB - LB);
    }
    return 0;
}