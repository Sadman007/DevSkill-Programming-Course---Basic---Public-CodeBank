#include <bits/stdc++.h>
using namespace std;

int coin[25];

int checkBit(int n,int pos)
{
    return n&(1<<pos);
}

int getSum(int value,int p)
{
    int sum = 0;
    for(int i = p-1;i>=0;i--)
    {
        if(checkBit(value,i)!=0) sum+=coin[i];
    }
    return sum;
}

int solve(int target,int p)
{
    /// generate 2^p combinations
    int total = 1<<p;
    for(int i=0;i<total;i++)
    {
        int generatedValue = getSum(i,p); /// getSum(5) ---> getSum(0[1]0[1]) --> coin[0]+coin[2]
        if(generatedValue == target) return 1;
    }
    return 0;
}

int main()
{
    /// O(T*2^p)
    int T;
    scanf("%d",&T);
    while(T--)
    {
        /// do my task
        int target,p;
        scanf("%d %d",&target,&p);
        for(int i=0;i<p;i++) /// O(p)
        {
            scanf("%d",&coin[i]);
        }
        int result = solve(target,p); /// O(2^p)
        if(result == 0) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
