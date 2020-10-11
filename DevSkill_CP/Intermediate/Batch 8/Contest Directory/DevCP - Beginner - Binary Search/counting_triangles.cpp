#include <bits/stdc++.h>
using namespace std;
#define MAX 100010
int arr[MAX + 5]; /// ALWAYS ei array gula globally niba. ALWAYS. Garbage value pichu charbena na hoy

int main()
{
    int n, T, cs = 1;
    scanf("%d", &T);
    while(T--) /// it's always better not to use 'i' as case loop initializer
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) /// array er value input neyar loop ta i thaka always valo. Readable hoy.
        {
            scanf("%d", &arr[i]); /**a,b,c eshob konodin array er naam dibana.
                                   Totally meaningless. Variable er naam meaningful hole code debug korata
                                   koyek gun easy hoye jay **/
        }
        sort(arr, arr + n);
        int tri_count = 0; /// ekhane 'ans' deyata baaje idea.
        for(int i = 0; i < n; i++) /// n - 2 use korar kono dorkar nai. Auto handle hobe niche
        {
            for(int j = i + 1; j < n; j++)
            {
                int ab = arr[i] + arr[j]; /// ab mane hocche a ar b bahur jogfol;
                int limit = (upper_bound(arr,arr + n,ab - 1) - arr) - (j + 1);
                tri_count += max(0, limit); /// limit jodi less than 0 hoy, auto 0 add hobe. :)
            }
        }
        printf("Case %d: %d\n",cs++,tri_count);
    }
    return 0;
}