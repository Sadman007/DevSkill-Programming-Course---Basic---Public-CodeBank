#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000
#define ll long long
#define MOD 1000000007
#define pii pair<int,int>
#define all(v) (v).begin(),(v).end()

int phi[MAX + 5];

void sieve_phi(int n)
{
    for(int i = 1; i <= n; i++)
        phi[i] = i;

    for(int i = 2; i <= n; i++)
    {
        if(phi[i] == i)
        {
            for(int j = i; j <= n; j += i)
            {
                phi[j] = phi[j] - (phi[j] / i);
            }
        }
    }
}

int main()
{
    sieve_phi(MAX);
    int T, p;
    scanf("%d", &T);
    while(T--)
    {
          scanf("%d", &p);
          printf("%d\n", phi[p]);
    }
    return 0;
}