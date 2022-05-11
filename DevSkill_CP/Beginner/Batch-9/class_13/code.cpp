#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long N) /// O(sqrt(N))
{
    if (N < 2) return false;
    for (int i = 2; 1LL * i * i <= N; i++) /// i * i <= N
    {
        if (N % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    long long N;
    while(cin >> N)
    {
        if (N == 0) break;
        long long sN = sqrtl(N);
        if (sN * sN == N) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}
