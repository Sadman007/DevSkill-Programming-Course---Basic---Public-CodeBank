#include <bits/stdc++.h>
using namespace std;
int arr[105],tmp[1050];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&arr[i]);
    if(n==1)
    {
        puts("YES");
        return 0;
    }
    bool flag = true;
    for(int i=0; i<n; i++)
    {
        tmp[arr[i]]++;
        if (tmp[arr[i]] >(( n+1) / 2))
        {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}
