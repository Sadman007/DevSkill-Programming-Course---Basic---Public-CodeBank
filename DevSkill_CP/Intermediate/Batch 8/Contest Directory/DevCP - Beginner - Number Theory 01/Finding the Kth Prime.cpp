#include <bits/stdc++.h>
using namespace std;
#define SZ 90000000
bool prime[SZ+5];
int vec[5000000+10];
int main()
{
    int idx=0;
    for(int i=2; i*i<=SZ; i++)
    {
        if(prime[i]==0)
        {
            for(int j=i*i; j<=SZ; j=j+i)
                prime[j]=1;
        }
    }
    for(int i=2; i<=SZ; i++)
    {
        if(idx>5000000) break;
        if(prime[i]==0)
            vec[idx++] = i;
    }
    int n, k;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &k);
        printf("%d\n", vec[k-1]);
    }

    return 0;
}