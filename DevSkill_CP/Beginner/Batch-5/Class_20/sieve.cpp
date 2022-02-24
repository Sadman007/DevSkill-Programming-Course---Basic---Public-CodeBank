#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100000000
bool marked[MAX + 5]; /// initialized with 0

/// TC: O(N*log(logN)) ~ O(N)
void performSieve(int n)
{
    marked[0] = marked[1] = 1;
    for(int i = 2; i * i <= n; i++)
    {
        if(marked[i] == 0)
        {
            for(int j = i * i; j <= n; j += i)
            {
                marked[j] = 1;
            }
        }
    }
    int cnt = 0;
    for(int i = 2; i <= n; i++)
        cnt += marked[i] == 0;
    cout << "total prime numbers from 1 to " << n << " is: " << cnt << "\n";
}

int main()
{
    performSieve(100000000);
    return 0;
}
