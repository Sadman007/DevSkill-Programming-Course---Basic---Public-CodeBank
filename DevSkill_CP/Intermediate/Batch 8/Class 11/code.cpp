#include <bits/stdc++.h>
using namespace std;

#define MAX 10000000
bool isComposite[MAX + 1];

/**
    SUM = (N/1) + N/2 + N/3 + (N/4) + N/5 + (N/6) + N/7 + (N/8) + (N/9) + (N/10) + ... + N/N
=>  SUM = N * (1 + 1/2 + 1/3 + 1/4 + 1/5 + 1/6 + ... + 1/N)
=>  SUM = N * (log2(N)) // approximate

**/

/// TC: O(N*log2(log2(N)) -> N = 10^7 -> NloglogN -> 4.5*10^7

void sieve(int N)
{
    isComposite[1] = 1;
    int sqn = sqrt(N) + 1;
    for(int i = 2; i <= sqn; i++)
    {
        if(isComposite[i] == 0)
        {
            for(int j = i * i; j <= N; j += i) /// N/2 + N/3 + N/5 + N/7 + N/11 ...
            {
                isComposite[j] = 1;
            }
        }
    }
    int prm_cnt = 0;
    for(int i = 1; i <= N; i++)
    {
        if(isComposite[i] == 0) prm_cnt++;
    }
    cout << prm_cnt << '\n';
}

/**
int dc[1010];

bool cmp(int x, int y)
{
    if(dc[x] == dc[y]) return x > y;
    return dc[x] < dc[y];
}

int arr[1010];
for(int i = 0; i < 1000; i++) arr[i] = i + 1;
sort(arr, arr + 1000, cmp)

int q;
cin >> q;
cout << arr[q - 1] << "\n"

**/

int main()
{
    sieve(10000000);
    return 0;
}
