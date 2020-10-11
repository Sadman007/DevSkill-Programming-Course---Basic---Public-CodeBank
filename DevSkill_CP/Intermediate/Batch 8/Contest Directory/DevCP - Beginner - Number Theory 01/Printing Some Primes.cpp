#include <bits/stdc++.h>
using namespace std;
#define SZ 100000001
bitset<SZ+2>prime;

int main()
{
    prime.reset();
    for(int i=2; i*i<=SZ; i++)
    {
        if(prime[i]==0)
        {
            for(int j=i*i; j<=SZ; j=j+i)
                prime[j]=1;
        }
    }
    int idx = 0;
    for(int i=2; i<=SZ; i++)
    {
        if(prime[i]==0){
            if(idx%100 == 0) printf("%d\n",i);
            idx++;
        }
    }
    return 0;
}