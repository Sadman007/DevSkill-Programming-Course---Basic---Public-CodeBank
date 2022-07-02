#include <bits/stdc++.h>
using namespace std;

const int M = 1000000;
int nod[M + 5];

void precalculate() /// O(NlogN)
{
    for(int i = 1; i <= M; i++)
        for(int j = i; j <= M; j+=i)
            nod[j]++;
}

/// O((T + N)*logN)
int main()
{
    precalculate();
    int T, a, b;
    scanf("%d", &T);
    /// O(T*logN)
    while(T--)
    {
       scanf("%d%d", &a, &b);
       printf("%d\n", nod[__gcd(a, b)]);
    }
}
