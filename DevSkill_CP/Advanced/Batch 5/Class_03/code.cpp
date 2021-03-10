#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000

int T[MAX + 5][22];
int arr[MAX + 5], logArray[MAX + 5];

void construct(int n) /// O(NlogN)
{
    // log table generation
    logArray[1] = 0;
    for(int i = 2; i <= n; i++)
        logArray[i] = 1 + logArray[i / 2];

    // arr = 0, 1, 2, 3, 4
    // sample = 1, 2, -4, 3, 7, 10, 2
    // base case
    for(int i = 0; i < n; i++)
        T[i][0] = arr[i];

    int K = logArray[n] + 1;

    for(int j = 1; j <= K; j++)
    {
        for(int i = 0; i + (1 << (j - 1)) < n; i++)
        {
            T[i][j] = min(T[i][j - 1], T[i + (1 << (j - 1))][j - 1]);
        }
    }
    // T[0...n-1][1]
    // T[0...n-1][2]
    // ...
    // T[0...n-1][K]
}

int query(int L, int R) /// O(1)
{
    int len = R - L + 1;
    if(len <= 0) return INT_MAX;
    int lg = logArray[len];
    return min(T[L][lg], T[R - (1 << lg) + 1][lg]);
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    construct(n);
    int Q;
    cin >> Q;
    while(Q--)
    {
        int L, R;
        cin >> L >> R;
        cout << query(L, R) << "\n";
    }
    return 0;
}
