#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 1000000

vector<int>divisors[MAX + 5]; /// total variables nlogn

/// O(nlogn)
void sieve_div(int n)
{
    for (int divisor = 1; divisor <= n; divisor++)
    {
        for (int candidate = divisor; candidate <= n; candidate += divisor)
        {
            divisors[candidate].push_back(divisor);
        }
    }
}

int main()
{
    sieve_div(MAX);
    int T;
    scanf("%d", &T);
    while(T--) {
        int a, b;
        scanf("%d %d", &a, &b);
        int g = __gcd(a, b);
        printf("%d\n", (int)divisors[g].size());
    }
    return 0;
}
