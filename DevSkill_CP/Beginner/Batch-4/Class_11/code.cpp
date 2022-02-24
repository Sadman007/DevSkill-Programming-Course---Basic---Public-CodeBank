#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
int arr[MAX + 10];

bool isPossible(int X) /// O(N)
{

}

int main()
{
    int t, n, q;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &q);
        for(int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        sort(arr, arr + n);
        int L = 1;
        int R = arr[n - 1];
        int M;
        while(L < R)
        {
            M = (L + R + 1) / 2;
            if(isPossible(M)) L = M;
            else R = M - 1;
        }
        printf("%d\n", R);
    }
    return 0;
}
