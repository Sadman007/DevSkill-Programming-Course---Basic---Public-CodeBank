#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
#define ll long long
#define MOD 1000000007
#define pii pair<int,int>
#define all(v) (v).begin(),(v).end()

bool prm[MAX + 5];
vector<int>vprm;

void sieve()
{
    for(int i = 2; i * i <= MAX; i++)
    {
        if(prm[i] == 0)
        {
            for(int j = i * i; j <= MAX; j += i)
            {
                prm[j] = 1;
            }
        }
    }
    for(int i = 2; i <= MAX; i++)
    {
        if(prm[i] == 0) vprm.push_back(i);
    }
}

int get_phi(int n)
{
    int res = n;
    for(int i = 0; i < (int)vprm.size() && vprm[i]*vprm[i] <= n; i++)
    {
        if(n % vprm[i] == 0)
        {
            while(n % vprm[i] == 0)
            {
                n /= vprm[i];
            }
            res -= res / vprm[i];
        }
    }
    if(n > 1) res -= res / n;
    return res;
}

int main()
{
    sieve();
    int n;
    while(scanf("%d", &n) == 1)
    {
        if(n == 0) break;
        printf("%d\n", get_phi(n));
    }
    return 0;
}
