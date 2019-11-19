#include <bits/stdc++.h>
using namespace std;
#define MAX 10010
int n,m;

struct newInt
{
    int num;
    bool operator<(newInt &b)
    {
        int ma = num % m;
        int mb = b.num % m;

        if(ma == mb)
        {
            if(num%2 == b.num%2 && num%2 == 1)
            {
                if(num > b.num) return true;
                return false;
            }
            if(num%2 == b.num%2 && num%2 == 0)
            {
                if(num < b.num) return true;
                return false;
            }
            if(num%2 == 1 && b.num%2==0) return true;
            return false;
        }

        if(ma < mb) return true;
        return false;
    }
};

newInt arr[MAX+10];

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++) scanf("%d",&arr[i].num);
    sort(arr,arr+n);
    for(int i=0;i<n;i++) printf("%d\n",arr[i].num);
    return 0;
}
