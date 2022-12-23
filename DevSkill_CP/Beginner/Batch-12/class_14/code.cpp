#include <bits/stdc++.h>
using namespace std;

const int MAX = 10000000;
bool marked[MAX + 5];

void sieve(int N)
{
    marked[0] = 1;
    marked[1] = 1;
    for (int i = 2; i * i <= N; i++)
    {
        if (marked[i] == 0)
        {
            for (int j = i * i; j <= N; j += i)
            {
                marked[j] = 1;
            }
        }
    }
    int cnt = 0;
    for (int i = 2; i <= N; i++)
    {
        if (marked[i] == 0)
        {
            ++cnt;
        }
    }
    cout << cnt << "\n";
}

int main()
{
    int N = 10000000; // 66****
    sieve(N);
    return 0;
}
