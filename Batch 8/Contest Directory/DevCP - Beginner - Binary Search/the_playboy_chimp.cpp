#include<bits/stdc++.h>
using namespace std;

int arr[50005];

int main()
{
    int N, Q, val;
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    scanf("%d", &Q);

    while(Q--)
    {
        scanf("%d", &val);
        int lo = lower_bound(arr, arr + N, val) - arr;
        int hi = upper_bound(arr, arr + N, val) - arr;
        if(lo == 0)
        {
            printf("X ");
        }
        else printf("%d ", arr[lo - 1]);

        if(hi == N)
        {
            printf("X\n");
        }
        else printf("%d\n", arr[hi]);
    }

    return 0;
}