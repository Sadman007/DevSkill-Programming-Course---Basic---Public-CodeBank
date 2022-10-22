#include <bits/stdc++.h>
using namespace std;

const int MAX = 100050;
int arr[MAX + 5], L[MAX + 5], R[MAX + 5], V[MAX + 5];
long long updateCnt[MAX + 5], coeff[MAX + 5];

int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d %d %d", &L[i], &R[i], &V[i]);
    }
    for (int i = 1; i <= k; i++)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        updateCnt[l]++;
        updateCnt[r + 1]--;
    }
    for (int i = 1; i <= m; i++)
    {
        updateCnt[i] += updateCnt[i - 1];
    }
    for (int i = 1; i <= m; i++)
    {
        coeff[L[i]] += updateCnt[i] * V[i];
        coeff[R[i] + 1] -= updateCnt[i] * V[i];
    }
    for (int i = 1; i <= n; i++)
    {
        coeff[i] += coeff[i - 1];
        printf("%lld ", coeff[i] + arr[i]);
    }
    return 0;
}
