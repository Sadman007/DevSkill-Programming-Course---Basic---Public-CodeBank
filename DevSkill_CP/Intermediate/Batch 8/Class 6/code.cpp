#include <bits/stdc++.h>
using namespace std;

int UB(vector<int>&arr, int v)
{
    int L = 0;
    int R = arr.size();
    int M;
    while(L < R)
    {
        M = L + (R - L)/2;
        if(arr[M] <= v) L = M + 1;
        else R = M;
    }
    return L;
}
int LB(vector<int>&arr, int v)
{
    int L = 0;
    int R = arr.size();
    int M;
    while(L < R)
    {
        M = L + (R - L)/2;
        if(arr[M] < v) L = M + 1;
        else R = M;
    }
    return L;
}

vector<int>arr;

int main()
{
    int v, T, N, Q, cs = 1;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &N, &Q);
        arr.clear();
        for(int i = 0; i < N; i++)
        {
            scanf("%d", &v);
            arr.push_back(v);
        }
        printf("Case %d:\n", cs++);
        while(Q--)
        {
            int L, R;
            scanf("%d %d", &L, &R);
            printf("%d\n", UB(arr, R) - LB(arr, L));
        }
    }
    return 0;
}
