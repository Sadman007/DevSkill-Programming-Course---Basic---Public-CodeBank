#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
#define ll long long
#define MOD 1000000007
#define pii pair<int,int>
#define all(v) (v).begin(),(v).end()

int phi[MAX + 5];

void sieve_phi(int n)
{
    for(int i = 0; i <= n; i++)
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
    sieve_phi(100);
    for(int i = 1; i <= 30; i++)
        cout << i << " : " << phi[i] << '\n';
    return 0;
}
