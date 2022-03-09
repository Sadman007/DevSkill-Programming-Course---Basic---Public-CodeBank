#include <bits/stdc++.h>
using namespace std;

int cachePrime[1001];

/// cachePrime[6] = 0
/// cachePrime[n] = 0, 1

/// O(sqrt(n))
bool isPrime(int n)
{
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0) return false;
    }
    return true;
}

int findShortestMove(int A, int B)
{
    vector<int> distance(B + 1, 100000);
    queue<int> Q;
    Q.push(A);
    distance[A] = 0;

    /// A -> B
    /// # nodes = B - A = N
    /// O(N)
    while(!Q.empty())
    {
        int u = Q.front(); /// u ---> v ; v = u + x ; x is a prime factor of u
        Q.pop();
        if (u == B) return distance[B];
        for (int x = 2; x < u; x++)
        {
            if (u % x == 0 && cachePrime[x])
            {
                int v = u + x;
                if (distance[v] == 100000 && v <= B)
                {
                    distance[v] = distance[u] + 1;
                    Q.push(v);
                }
            }
        }
    }

    return -1;
}

/// O(N(T + sqrt(N)))
int main()
{
    /// O(N * sqrt(N))
    for (int i = 2; i <= 1000; i++)
    {
        cachePrime[i] = isPrime(i);
    }
    /// O(T * N)
    int T, cs = 1;
    scanf("%d", &T);
    while(T--)
    {
        int A, B;
        scanf("%d %d", &A, &B);
        printf("Case %d: %d\n", cs++, findShortestMove(A, B));
    }
    return 0;
}
