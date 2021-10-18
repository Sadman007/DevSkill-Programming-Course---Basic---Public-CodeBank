#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 500000

int phi[MAX + 5];
vector<int>divs[MAX + 5];
void euler_sieve()
{
    for(int i = 1; i <= MAX; i++)
    {
        phi[i] = i;
    }
    for(int i = 2; i <= MAX; i++)
    {
        if(phi[i] == i)
        {
            for(int j = i; j <= MAX; j += i)
            {
                phi[j] /= i;
                phi[j] *= (i - 1);
            }
        }
    }
}

int main()
{
    //euler_sieve();
    for(int i = 1; i <= MAX; i++)
        for(int j = i; j <= MAX; j += i)
            divs[j].push_back(i);

    int n, k, t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &k);
        int sum = 0;
        for(int dv : divs[n])
        {
            if(dv % k != 0)
                sum += dv;
        }
        printf("%d\n", sum);
    }
    return 0;
}
